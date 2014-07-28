#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>

#include "message/proto/login.pb.h"
#define MAXLINE 4096

using namespace std;

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
    servaddr.sin_port   = htons (1300);
    if (::inet_pton (AF_INET, *(argv+1), &servaddr.sin_addr.s_addr) < 0)
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

#if 0
        string sLogin;
        Login  login;
        sLogin = recvbuf;
        login.ParseFromString (sLogin);
        cout << "id = " << login.clientid () << endl; 
        cout << "type = " << login.clienttype () << endl; 
        cout << "login username = " << login.username () << endl;
        cout << "login password = " << login.password () << endl;
#else
#if 0
        string sVector3;
        cVector3 vec3;
        sVector3 = recvbuf;
        vec3.ParseFromString (sVector3);
        cout << "x = " << vec3.x() << endl; 
        cout << "y = " << vec3.y() << endl; 
        cout << "z = " << vec3.z() << endl;
#else
#if 0
        string sNode;
        cBufferNode node;
        sNode = recvbuf;
        node.ParseFromString (sNode);
        cout << "id = " << node.id () << endl;
        cout << "type = " << node.type () << endl;
        cout << "value = " << node.value () << endl;
#else
        string sNode;
        cTankNode node;
        cVector3 vec3;
        cBufferNode bn;

        sNode = recvbuf;
        node.ParseFromString (sNode);

        cout << "id = " << node.id () << endl;
        cout << "position.x  = " << node.position().x()  << endl;
        cout << "position.y  = " << node.position().y()  << endl;
        cout << "position.z  = " << node.position().z()  << endl;
        cout << "direction.x = " << node.direction().x() << endl;
        cout << "direction.y = " << node.direction().y() << endl;
        cout << "direction.z = " << node.direction().z() << endl;

        int size = node.list_size ();
        for (int i=0; i<size; i++) {
            bn = node.list (i);
            cout << "buffer" << i << ".id = " << bn.id () << endl;
            cout << "buffer" << i << ".type = " << bn.type () << endl;
            cout << "buffer" << i << ".value = " << bn.value () << endl;
        }

        cout << "hp = " << node.hp () << endl;
#endif
#endif
#endif
    }

    if (n < 0)
    {
        perror ("read");
        exit (1);
    }

    return (0);
}
