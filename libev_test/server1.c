#include <stdio.h>                                                                                                
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/fcntl.h>
#include <ev.h>

#define D(result, exp, fmt, ...) do {                   \
    if (exp) {                               \
        fprintf (stderr, fmt, ##__VA_ARGS__);   \
        result;                              \
    }                                           \
} while (0)

typedef struct ev_io_info
{
    struct ev_io        *io;
    ev_tstamp           lasttime;
} EV_IO_INFO;

static struct ev_loop *g_loop;
static EV_IO_INFO ioarray[10240];

void recv_callback (struct ev_loop *loop, ev_io *w, int revents)
{
    char buf[64];
    ssize_t read;

    D (return, EV_ERROR&revents, "error event in read");

    read = recv (w->fd, buf, 64, 0);
    D (return, read<0, "read error, errno: %d\n", errno);

    if (read == 0) {
        fprintf (stdout, "someone disconnected!\n");
        ev_io_stop (g_loop, w);
        free (w);
        return;
    }
    else {
        printf ("get message is: %s\n", buf);
    }

    send (w->fd, buf, read, 0);
    bzero (buf, read);
}

void accept_callback (struct ev_loop *loop, ev_io *w, int revents)
{
    struct sockaddr_in c_addr;
    socklen_t socklen = sizeof (c_addr);
    int client_fd;
    client_fd = accept (w->fd, (struct sockaddr*) &c_addr, &socklen);
    D (return, client_fd < 0, "accept: %s[errno=%d]\n", strerror (errno), errno);

    printf ("client connected! fd=[%d], ip=[%s], port=[%d]\n",
            client_fd, 
            inet_ntoa (c_addr.sin_addr),
            htons (c_addr.sin_port));

    fcntl (client_fd, F_SETFL, fcntl (client_fd, F_GETFL, 0) | O_NONBLOCK);

    ioarray[client_fd].io = (ev_io*) malloc (sizeof (ev_io));
    ioarray[client_fd].lasttime = ev_time ();

    // 初始化一个ev_io为新的client_fd, 且加入到g_loop中
    ev_io_init (ioarray[client_fd].io, recv_callback, client_fd, EV_READ);
    ev_io_start (g_loop, ioarray[client_fd].io);
}

int main (int argc, char** argv)
{
    int listenfd;
    int rlt;
    int socket_flag = 1;

    // 检查程序参数
    if (argc != 3) {
        printf ("usage: %s <address> <port>.\n", argv[0]);
        return (1);
    }

    // 创建一个监听套接字
    listenfd = socket (AF_INET, SOCK_STREAM, 0);
    D (return (1), listenfd < 0, "socket: %s[errno=%d]\n", strerror (errno), errno);

    // 设置监听套接字为非堵塞模式
    fcntl (listenfd, F_SETFL, fcntl (listenfd, F_GETFL, 0) | O_NONBLOCK);

    // 设置监听套接字可重用
    setsockopt (listenfd, SOL_SOCKET, SO_REUSEADDR, &socket_flag, sizeof (socket_flag));

    // 设置监听套接字为Nodelay, 使用一次大数据的写操作，而不是多次小数据的写操作
    setsockopt (listenfd, IPPROTO_TCP, TCP_NODELAY, &socket_flag, sizeof (socket_flag));

    // 绑定套接字
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr (argv[1]);
    servaddr.sin_port = htons (atoi (argv[2]));
#if 1
    rlt = bind (listenfd, (struct sockaddr*) &servaddr, sizeof (struct sockaddr));
    D (return (1), rlt < 0, "bind: %s[errno=%d]\n", strerror (errno), errno);
#else
    if (bind (listenfd, (struct sockaddr*) &servaddr, sizeof (struct sockaddr)) < 0) {
        perror ("bind:");
        return (1);
    }

#endif

    // 监听
    listen (listenfd, 0);


    // 创建一个事件循环g_loop
    g_loop = ev_loop_new (EVBACKEND_EPOLL);
    D (return (1), g_loop == NULL, "no epoll found here, maybe it hides under your chair");

    // 分配空间给ev_io
    ev_io *ev_io_watcher = (ev_io*) malloc (sizeof (ev_io));
    D (return (1), ev_io_watcher == NULL, "out of memory for ev_io use malloc");

    // 为listenfd初始化一个ev_io_watcher, 当listenfd为可读[EV_READ]时,
    // 则调用accept_callback进行可读事件的回调处理
    ev_io_init (ev_io_watcher, accept_callback, listenfd, EV_READ);

    // 将为包装了可读事件,回调函数,和listenfd的ev_io加入到事件循环 g_loop
    ev_io_start (g_loop, ev_io_watcher);

    // 开始事件循环
    ev_loop (g_loop, 0);    // 这里会一直循环

    // 退出事件循环时, 摧毁掉事件循环g_loop
    ev_loop_destroy (g_loop);

    free (ev_io_watcher);
}
