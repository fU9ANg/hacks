
// for test
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string>

#define MSG_HEAD_LEN sizeof(struct sSubmitData)

using namespace std;

struct so {
    int     fd;
    string  val;
};

int select_version (int* fd)
{
    int c_fd = *fd;
    fd_set rset, wset;
    struct timeval tval;

    FD_ZERO (&rset);
    FD_SET (c_fd, &rset);

    wset = rset;
    tval.tv_sec = 0;
    tval.tv_usec = 300 * 1000;

    int ready_n;
    if ((ready_n = select (c_fd + 1, &rset, &wset, NULL, &tval)) == 0) {
        close (c_fd);
        errno = ETIMEDOUT;
        perror ("select timeout:");
        return (-1);
    }

    if (FD_ISSET (c_fd, &rset)) {
        int error;
        socklen_t len = sizeof (error);
        if (getsockopt (c_fd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
            perror ("getsockopt error:");
            return (-1);
        }
        cout << "in read set, error=" << error << endl;
    }

    if (FD_ISSET (c_fd, &wset)) {
        int error;
        socklen_t len = sizeof (error);
        if (getsockopt (c_fd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
            perror ("getsockopt error:");
            return (-1);
        }
        cout << "in write set, error=" << error << endl;
    }

    return (0);
}

int main (int argc, char* argv[])
{
    string ip = "127.0.0.1";
    int port = 9887;
    int c_fd, flags, ret;
    struct sockaddr_in s_addr;

    (void) memset (&s_addr, 0, sizeof (s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons (port);
    s_addr.sin_addr.s_addr = inet_addr (ip.c_str());


    if ((c_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("socket:");
        exit (1);
    }

    flags = fcntl(c_fd, F_GETFL, 0);
    if (flags < 0) {
        perror("get socket flags fail.\n");
        return -1;
    }

    if (fcntl(c_fd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("set socket O_NONBLOCK fail.\n");
        return -1;
    }

    ret = connect(c_fd, (struct sockaddr*) &s_addr, sizeof (struct sockaddr));
    while (ret < 0) {
        if (errno == EINPROGRESS) {
            break;
        } else {
            perror("connect remote server fail.\n");
            printf("%d\n", errno);
            exit(0);
        }
    }
    select_version (&c_fd);

    return (0);
}
