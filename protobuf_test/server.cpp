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
        write (connfd, sStr.c_str(), sStr.size ());
/*
        pbTank node;
        pbVector3 *vec3 = NULL;

        node.set_id (1000);
        vec3 = new cVector3;
        vec3->set_x ("111.11");
        vec3->set_y ("222.22");
        vec3->set_z ("333.33");
        node.set_allocated_position (vec3);
       
        vec3 = new cVector3;
        vec3->set_x ("444.44");
        vec3->set_y ("555.55");
        vec3->set_z ("666.66");
        node.set_allocated_direction (vec3);
       
        node.set_hp (100);
        
        
        pbBuffer* bn;
        for (int i=0; i<2; i++) {
            bn = node.add_list ();
            bn->set_id (801);
            bn->set_type (5);
            bn->set_value (900);
        }
        
        string sNode;
        node.SerializeToString (&sNode);
        write (connfd, sNode.c_str(), sNode.size ());
*/
        
        close (connfd);
    }

    close (listenfd);
}
