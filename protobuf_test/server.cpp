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
#if 0
        Login login;
        login.set_clientid (11111);
        login.set_clienttype (123);
        login.set_quality (10.50);
        cout << "quality = " << login.quality() << endl;
        login.set_username ("zhangsan");
        login.set_password ("zhangsan123456");
        string sLogin;
        login.SerializeToString (&sLogin);
        cout << "string = " << sLogin << endl;
        write (connfd, sLogin.c_str(), sLogin.size());
#else
#if 0
        cVector3 vec3;
        vec3.set_x ("111.11");
        vec3.set_y ("222.22");
        vec3.set_z ("333.33");
        string sVector3;
        vec3.SerializeToString (&sVector3);
        cout << "string = " << sVector3 << endl;
        write (connfd, sVector3.c_str(), sVector3.size());
#else
#if 0
        cBufferNode node;
        node.set_id (100);
        node.set_type (2);
        node.set_value (6);
        string sNode;
        node.SerializeToString (&sNode);
        write (connfd, sNode.c_str(), sNode.size ());
#else

        cTankNode node;
        cVector3 *vec3 = NULL;
        node.set_id (1000);
        //cVector3 *vec3 = node.mutable_position();
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
        
        
        cBufferNode* bn;
        for (int i=0; i<2; i++) {
            bn = node.add_list ();
            bn->set_id (801);
            bn->set_type (5);
            bn->set_value (900);
        }
        

        string sNode;
        node.SerializeToString (&sNode);
        write (connfd, sNode.c_str(), sNode.size ());
#endif
#endif
#endif

        
        close (connfd);
    }

    close (listenfd);
}
