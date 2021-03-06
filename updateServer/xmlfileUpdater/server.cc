
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
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <string>

#include "utils.h"
#include "updater.pb.h"

using namespace std;

#define SERV_PORT   15432
#define SERV_ADDR   "192.168.0.254"


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
    // FD_ZERO (&writefds);
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
                        // TODO:
                        cout << "operator xml file" << endl;
                        string fileName = "./outoutout.xml";
                        //buildXML (fileName);
                        //dumpXML (fileName);

        updater update;
#if 0
        update.set_major (1);
        update.set_minor (10);
        update.set_size  (100);  // default xxx KB
        update.set_date  ("2013/01/12 12:01:02");
        update.set_addr  ("http://222.186.50.76:9090/static/server-7.13.tar.gz");
#endif

        int ffd, nread = 0;
        string fcontent;
        char buffer[MAX_BUFF_SIZE];
        if ((ffd = open (fileName.c_str(), O_RDONLY)) < 0)
        {
            cout << "[Error]: can't open outoutout.xml" << endl;
            exit (1);
        }
        (void) memset (buffer, 0x00, sizeof (buffer));
        while ((nread = read (ffd, &buffer[0], MAX_BUFF_SIZE)) > 0)
        {
            string tmpStr = buffer;
            fcontent += tmpStr;
            (void) memset (buffer, 0x00, sizeof (buffer));
            
        }

        update.set_content (fcontent.c_str());

        string  s_update;
        update.SerializeToString (&s_update);

        cout << fcontent.c_str() << endl;
        cout << "writing ... s_update string." << endl;
        write (fd, s_update.c_str(), s_update.size());
                        
                        //(void) write (fd, &ch, 1);
                    }
                }
            }
        }
    }

    return (EXIT_SUCCESS);
}
