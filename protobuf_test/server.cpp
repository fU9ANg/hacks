#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

#include <iostream>
#include <string>

#include "message/proto/protocol.pb.h"

#include "RpcManager.h"

#define MAXLINE 4096
using namespace std;

string packet (void)
{
    ServerProtocol::pbGetTankListRet GetTankListRet_;
    pbTank*          tank_ = NULL;
    pbVector3*       vec3_ = NULL;
    pbBuffer*        buffer_ = NULL;
    for (int i=100; i<103; i++) {
        tank_ = GetTankListRet_.add_list ();
        if (tank_) {
            // id
            tank_->set_id (i);

            // position
            vec3_ = new pbVector3;
            vec3_->set_x (2*i + i);
            vec3_->set_y (3*i + i);
            vec3_->set_z (1*i + i);
            tank_->set_allocated_pos (vec3_);

            // direction
            vec3_ = new pbVector3;
            vec3_->set_x (4*i + i);
            vec3_->set_y (5*i + i);
            vec3_->set_z (6*i + i);
            tank_->set_allocated_dir (vec3_);

            // hp
            tank_->set_hp (100);

            // buffer list
            for (int j=1; j<5; j++) {
                buffer_ = tank_->add_list ();
                if (buffer_) {
                    buffer_->set_id (j);
                    vec3_ = new pbVector3;
                    vec3_->set_x (1*j + j);
                    vec3_->set_y (2*j + j);
                    vec3_->set_z (3*j + j);
                    buffer_->set_allocated_pos (vec3_);
                    buffer_->set_type (50);
                    buffer_->set_value (190);
                }
            }
        }
    }
    string sStr;
    GetTankListRet_.SerializeToString (&sStr);
    return (sStr);
}

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


    RPCMANAGER->InitFunctionMap();

    while (1)
    {
        clilen = sizeof (cliaddr);
        if ((connfd = accept (listenfd, (struct sockaddr *) &cliaddr, \
                              &clilen)) < 0)
        {
            perror ("accept");
            exit (1);
        }

        // recv
        char recvbuf[MAXLINE];
        int n;
        if ((n = read (connfd, recvbuf, sizeof (recvbuf))) > 0) {
                recvbuf[n] = 0x00;


                int index_ = *(int*) recvbuf;
                printf ("index = %i\n", index_);

#if 1
                RPCMANAGER->StartFunctionCall (recvbuf);
#else
#endif
        }

        if (n < 0) {
                perror ("read");
                exit (1);
        }

        // send
        cout << "Response Message To Client." << endl;
        string sStr = packet ();
        write (connfd, sStr.c_str(), sStr.size ());
        
        close (connfd);
    }

    close (listenfd);
}
