#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MAXLINE 4096

int
main (int argc, char ** argv)
{
    int    n, sockfd;
    char   recvbuf[MAXLINE];
    struct sockaddr_in servaddr;
    
    if (argc != 2)
    {
        printf ("usage: %s <ip address>.\n", *argv);
        exit (1);
    }

    if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror ("socket");
        exit (1);
    }

    memset (&servaddr, 0x00, sizeof (servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons (13);
    if (inet_pton (AF_INET, *(argv+1), &servaddr.sin_addr.s_addr) < 0)
    {
        perror ("inet_pton");
        exit (1);
    }

    if ((connect (sockfd, (struct sockaddr *) &servaddr, sizeof (servaddr))) < 0)
    {
        perror ("connect");
        exit (1);
    }

    while ((n = read (sockfd, recvbuf, sizeof (recvbuf))) > 0)
    {
        recvbuf[n] = 0x00;
        if (fputs (recvbuf, stdout) == EOF)
        {
            perror ("fputs");
            exit (1);
        }
    }

    if (n < 0)
    {
        perror ("read");
        exit (1);
    }

    return (0);
}
