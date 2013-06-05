#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

#include <iostream>
#include <string>

#include "message/proto/login.pb.h"

#define MAXLINE 4096
using namespace std;

int
main (int argc, char **argv)
{
    int    listenfd, connfd;
    socklen_t clilen;
    struct sockaddr_in servaddr, cliaddr;

    if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror ("socket");
        exit (1);
    }

    int opt = 1;
    setsockopt (listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt));

    (void) memset (&servaddr, 0x00, sizeof (servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_port        = htons (1300);
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

        Login login;

        login.set_clientid (11111);
        login.set_clienttype (123);
#if 1
        //login.set_quality (0.40f);     //error
#else
        login.set_quality (.13f);     //it's ok
#endif
        cout << "quality = " << login.quality() << endl;
        login.set_username ("zhangsan");
        login.set_password ("zhangsan123456");

        string sLogin;
        login.SerializeToString (&sLogin);
        cout << "string = " << sLogin << endl;

        write (connfd, sLogin.c_str(), sLogin.size());
        
        close (connfd);
    }

    close (listenfd);
}
