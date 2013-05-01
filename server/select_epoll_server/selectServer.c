
/*
 * Written by fU9ANg
 * 2013
 * bb.newlife@gmail.com
 */

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

#define SERV_PORT   15432
#define SERV_ADDR   "127.0.0.1"

int main (int argc, char** argv)
{
    struct sockaddr_in servAddr;
    socklen_t   servLen;
    int listenfd, newclient;
    fd_set readfds, testfds;

    if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("ERROR: socket()");
        return (EXIT_FAILURE);
    }

    servLen = sizeof (servAddr);
    (void) memset (&servAddr, 0x00, servLen);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons (SERV_PORT);
    (void) inet_pton (AF_INET, SERV_ADDR, &servAddr.sin_addr.s_addr);

    if (bind (listenfd, (struct sockaddr*)&servAddr, servLen) < 0) {
        perror ("ERROR: bind()");
        return (EXIT_FAILURE);
    }

    listen (listenfd, 5);

    FD_ZERO (&readfds);
    //FD_ZERO (&writefds);
    //FD_ZERO (&exceptfds);
    FD_SET (listenfd, &readfds);
    while (1) {
        char ch;
        int fd;
        int nread;

        testfds = readfds;

        if (select (FD_SETSIZE, &testfds, NULL, NULL, NULL) < 0) {
            perror ("ERROR: select()");
            return (EXIT_FAILURE);
        }

        for (fd = 0; fd < FD_SETSIZE; fd++)
        {
            if (FD_ISSET (fd, &testfds))
            {
                if (fd == listenfd)
                {
                    if ((newclient = accept (listenfd, NULL, NULL)) < 0)
                    {
                        perror ("ERROR: accept()");
                        return (EXIT_FAILURE);
                    }
                    FD_SET (newclient, &readfds);
                    printf ("adding client on fd: %d\n", fd);
                }
                else
                {
                    ioctl (fd, FIONREAD, &nread);
                    if (nread == 0)
                    {
                        (void) close (fd);
                        FD_CLR (fd, &readfds);
                        printf ("remove client on fd: %d\n", fd);
                    }
                    else
                    {
                        (void) read (fd, &ch, 1);
                        (void) sleep (1);
                        printf ("serving client on fd: %d\n", fd);
                        ch++;
                        (void) write (fd, &ch, 1);
                    }
                }
            }
        }
    }

    return (EXIT_SUCCESS);
}
