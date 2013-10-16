

// 2013 by fU9ANg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> // for inet
#include <arpa/inet.h>  // for inet
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#include "sock.h"

int main (int argc, char** argv)
{
    int sock_fd;
    int len;
    struct sockaddr_in address;
    int result;

    if (argc != 3) {
        printf ("usage: %s <username> <password>\n", argv[0]);
        return (1);
    }

    if ((sock_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: socket ");
        return (1);
    }

    (void) memset (&address, 0x00, sizeof (struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr ("222.186.50.76");
    address.sin_port = htons (4231);
    len = sizeof (address);


    if ((result = connect (sock_fd, (struct sockaddr*) &address, len)) < 0) {
        perror ("oops: connect ");
        return (1);
    }

    char send_buff[128];
    sAuthInfo* autoInfo = (sAuthInfo*) send_buff;
    (void) memset (send_buff, 0x00, sizeof (send_buff));
    sprintf (autoInfo->username, "%s", argv[1]); 
    sprintf (autoInfo->password, "%s", argv[2]); 

    printf ("====send u= %s\n", autoInfo->username);
    printf ("----send p= %s\n", autoInfo->password);

    send_v (sock_fd, send_buff, 128);
    (void) memset (send_buff, 0x00, sizeof (send_buff));
    recv_v (sock_fd, send_buff, 1);

    printf ("recv character=%d\n", send_buff[0]);
    if (send_buff[0] == 0)
        printf ("not authorize\n");
    else if (send_buff[0] == 1)
        printf ("authorize\n");
    else
        printf ("invalid authorize flag\n");

    if (sock_fd)
        close (sock_fd);

    return (0);
}
