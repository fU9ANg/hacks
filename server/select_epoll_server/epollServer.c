
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

#define MAX_EVENTS  10240

int Receiv (int fd);

int main (int argc, char** argv)
{
    struct sockaddr_in servAddr;
    socklen_t   servLen;
    int listenfd, newclient, epollfd;
    struct epoll_event ev;
    struct epoll_event events[MAX_EVENTS];


    if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("ERROR: socket()");
        return (EXIT_FAILURE);
    }

    servLen = sizeof (servAddr);
    (void) memset (&servAddr, 0x00, servLen);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons (SERV_PORT);
    inet_pton (AF_INET, SERV_ADDR, &servAddr.sin_addr.s_addr);

    if (bind (listenfd, (struct sockaddr*)&servAddr, servLen) < 0) {
        perror ("ERROR: bind()");
        return (EXIT_FAILURE);
    }

    listen (listenfd, 5);

    if ((epollfd = epoll_create (MAX_EVENTS)) < 0)
    {
        perror ("ERROR: epoll_crate()");
        return (EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listenfd;
    if (epoll_ctl (epollfd, EPOLL_CTL_ADD, listenfd, &ev) < 0)
    {
        perror ("ERROR: epoll_ctl()");
        return (EXIT_FAILURE);
    }

    int nfds = 0;
    int i;
    while (1) {
        if ((nfds = epoll_wait (epollfd, events, MAX_EVENTS, -1)) < 0)
        {
            perror ("ERROR: epoll_wait()");
            return (EXIT_FAILURE);
        }

        for (i=0; i<nfds; i++)
        {
            if (events[i].data.fd == listenfd)
            {
                if ((newclient = accept (listenfd, NULL, NULL)) < 0)
                {
                    perror ("ERROR: accept()");
                    return (EXIT_FAILURE);
                }

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd= newclient;

                if (epoll_ctl (epollfd, EPOLL_CTL_ADD, newclient, &ev) < 0)
                {
                    perror ("ERROR: epoll_ctl()");
                    return (EXIT_FAILURE);
                }

                printf ("accepting client on fd: %d\n", newclient);
                return (EXIT_SUCCESS);
            }
            else
                Receiv (events[i].data.fd);
        }
    }

    return (EXIT_SUCCESS);
}

int Receiv (int fd)
{
    int nread;
    char ch;
    ioctl (fd, FIONREAD, &nread);
    if (nread == 0)
    {
        close (fd);
        printf ("remove client on fd: %d\n", fd);
        return (EXIT_FAILURE);
    }
    read (fd, &ch, 1);
    sleep (1);
    printf ("serving client on fd: %d\n", fd);
    ch++;
    write (fd, &ch, 1);

    return (EXIT_SUCCESS);
}
