#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>

#include "message/proto/protocol.pb.h"

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

        string sRecvStr;
        ServerProtocol::pbGetTankListRet GetTankListRet_;
        pbTank tank;
        pbBuffer bn;

        sRecvStr = recvbuf;
        GetTankListRet_.ParseFromString (sRecvStr);

        for (int i=0; i<GetTankListRet_.list_size (); i++) {
            printf ("--------------------- Tank[%i] --------------------\n", i);
            tank = GetTankListRet_.list (i);
            cout << "id = " << tank.id () << endl;
            cout << "pos.x = " << tank.pos().x() << endl;
            cout << "pos.y = " << tank.pos().y() << endl;
            cout << "pos.z = " << tank.pos().z() << endl;
            cout << "dir.x = " << tank.dir().x() << endl;
            cout << "dir.y = " << tank.dir().y() << endl;
            cout << "dir.z = " << tank.dir().z() << endl;

            for (int j=0; j<tank.list_size(); j++) {
                printf ("++++ Buffer[%i] of Tank[%i] ++++\n", j, i);
                bn = tank.list (j);
                cout << "buffer" << i << ".id = " << bn.id () << endl;
                cout << "pos.x = " << bn.pos().x() << endl;
                cout << "pos.y = " << bn.pos().y() << endl;
                cout << "pos.z = " << bn.pos().z() << endl;
                cout << "buffer" << i << ".type = " << bn.type () << endl;
                cout << "buffer" << i << ".value = " << bn.value () << endl;
            }
            cout << "hp = " << tank.hp () << endl;
        }
    }

    if (n < 0)
    {
        perror ("read");
        exit (1);
    }

    return (0);
}
