#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

#define MAXLINE 4096

int
main (int argc, char **argv)
{
    int    listenfd, connfd, clilen;
    struct sockaddr_in servaddr, cliaddr;
    time_t ticks;
    char   sendbuf[MAXLINE];

    if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror ("socket");
        exit (1);
    }

    memset (&servaddr, 0x00, sizeof (servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_port        = htons (13);
    servaddr.sin_addr.s_addr = htonl (INADDR_ANY);

    if (bind (listenfd, (struct sockaddr *) &servaddr, sizeof (servaddr)) < 0)
    {
        perror ("bind");
        exit (1);
    }

    listen (listenfd, 5);

    while (1)
    {
        clilen = sizeof (cliaddr);
        if ((connfd = accept (listenfd, (struct sockaddr *) &cliaddr, \
                              &clilen)) < 0)
        {
            perror ("accept");
            exit (1);
        }

        ticks = time (NULL);
        snprintf (sendbuf, sizeof (sendbuf), "%.24s\r\n", ctime (&ticks));
        write (connfd, sendbuf, strlen (sendbuf));

        close (connfd);
    }

    close (listenfd);
}
