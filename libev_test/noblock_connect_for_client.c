#include <stdio.h>	
#include <string.h>	
#include <stdlib.h>
#include <sys/types.h>	
#include <errno.h>
#include <unistd.h>	
#include <fcntl.h>	
#include <sys/select.h>	
#include<sys/ioctl.h>//inet_addr ()	
#include <sys/socket.h>	
#include <netinet/in.h>	
#include <arpa/inet.h>

//#define PEER_IP	 "192.168.0.254"
#define PEER_IP	 "222.186.50.76"
#define PEER_PORT   9887

int main (int argc, char **argv)	
{	
    int ret = 0;	
    int sock_fd;	
    int flags;	
    struct sockaddr_in addr;	

    /* obtain a socket */	
    sock_fd = socket (AF_INET, SOCK_STREAM, 0);	

    /* set non-blocking mode on socket*/	
#if 1	
    flags = fcntl (sock_fd, F_GETFL, 0);	
    fcntl (sock_fd, F_SETFL, flags|O_NONBLOCK);	
#else	
    int imode = 1;	
    ioctl (sock_fd, FIONBIO, &imode);	
#endif	

    /* connect to server */	
    addr.sin_family  = AF_INET;	
    addr.sin_port  = htons (PEER_PORT);	
    addr.sin_addr.s_addr = inet_addr (PEER_IP);	
    int res = connect (sock_fd, (struct sockaddr *)&addr, sizeof (struct sockaddr_in));	
    if (0 == res) {	
        printf ("socket connect succeed immediately.\n");	
        ret = 0;	
    } else {	
        printf ("get the connect result by select ().\n");	
        if (errno == EINPROGRESS)	
        {	
            int times = 0;	
            while (times++ < 5)	{	
                fd_set rfds, wfds;	
                struct timeval tv;	

                printf ("errno = %d\n", errno);	
                FD_ZERO (&rfds);	
                FD_ZERO (&wfds);	
                FD_SET (sock_fd, &rfds);	
                FD_SET (sock_fd, &wfds);	

                /* set select () time out */	
                tv.tv_sec = 10;	 
                tv.tv_usec = 0;	
                int selres = select (sock_fd + 1, &rfds, &wfds, NULL, &tv);	
                switch (selres)	{	
                    case -1:	
                        printf ("select error\n");	
                        ret = -1;	
                        break;	
                    case 0:	
                        printf ("select time out\n");	
                        ret = -1;	
                        break;	
                    default:	
                        if (FD_ISSET (sock_fd, &rfds) || FD_ISSET (sock_fd, &wfds)) {	
                            connect (sock_fd, (struct sockaddr *)&addr, sizeof (struct sockaddr_in));	
                            int err = errno;	
                            if  (err == EISCONN) {	
                                printf ("connect finished 111.\n");	
                                ret = 0;	
                            } else {	
                                printf ("connect failed. errno = %d\n", errno);	
                                printf ("FD_ISSET (sock_fd, &rfds): %d\nFD_ISSET (sock_fd, &wfds): %d\n", 
                                        FD_ISSET (sock_fd, &rfds) , FD_ISSET (sock_fd, &wfds));	
                                ret = errno;	
                            }	
                        }	
                        else {	
                            printf ("haha\n");	
                        }	
                }	

                if (-1 != selres && (ret != 0))	{	
                    printf ("check connect result again... %d\n", times);	
                    continue;	
                } else {	
                    break;	
                }	
            }	

        } else { // errno != EINPROGRESS
            printf ("connect to host %s:%d failed.\n", PEER_IP, PEER_PORT);	
            ret = errno;	
        }	
    }

    if (0 == ret) {	
        printf ("send data to server.\n");
        send (sock_fd, "12345", sizeof ("12345"), 0);	
    } else {	
        printf ("connect to host %s:%d failed.\n", PEER_IP, PEER_PORT);	
    }	

    close (sock_fd);	
    return ret;	
}
