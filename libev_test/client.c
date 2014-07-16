
// for test
#if 0
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>
#else
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
#endif

#define SERV_IP "192.168.0.254"
#define SERV_PORT 9887
#define CONNECT_TIMEOUT 5

#define MSG_HEAD_LEN sizeof(struct sSubmitData)

int main (int argc, char* argv[])
{
    int s = 0;
    int i  = 0;
    int error;
    s  = socket (AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        printf ("socket(): can't create socket");
    }
#if 1
    fcntl (s, F_SETFL, O_NONBLOCK);
#endif
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERV_IP);
    addr.sin_port = htons(SERV_PORT);

    if (connect (s, (struct sockaddr*) &addr, sizeof (addr)) < 0) {
        if (errno == EINPROGRESS){// it is in the connect process   
            struct timeval tv;   
            fd_set writefds;   
            tv.tv_sec = CONNECT_TIMEOUT;
            tv.tv_usec = 0;   
            FD_ZERO(&writefds);   
            FD_SET(s, &writefds);   
            if(select(s+1,NULL,&writefds,NULL,&tv)>0){   
                    int len=sizeof(int);   
                   //下面的一句一定要，主要针对防火墙   
                    getsockopt(s, SOL_SOCKET, SO_ERROR, &error, &len);   
                    if(error==0) {
                        printf ("111111111 connect success.\n");
                        char buff[4] = {'a', 'b', 'c', 'd'};
                        write (s, buff, sizeof (buff));
                    }
                    else {
                        printf ("111111111 connect failed.\n");
                    }
            }
            else {
                printf ("222222222 connect failed.\n"); //timeout or error happen   
            }
        }
        else {
            printf ("333333333 connect failed.\n");
        }
    }
    else {
        printf ("444444444 connect success.\n");
    }

    if (s) close (s);
    return 0;
}
