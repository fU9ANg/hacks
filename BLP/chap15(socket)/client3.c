

// 2012, 2013 by fU9ANg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> // for inet
#include <arpa/inet.h>  // for inet
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main (int argc, char** argv)
{
    int sock_fd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';

    if ((sock_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: socket ");
        return (1);
    }

    (void) memset (&address, 0x00, sizeof (struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr ("127.0.0.1");
    address.sin_port = htons (9999);
    len = sizeof (address);


    if ((result = connect (sock_fd, (struct sockaddr*) &address, len)) < 0) {
        perror ("oops: connect ");
        return (1);
    }

    write (sock_fd, &ch, 1);
    read (sock_fd, &ch, 1);

    printf ("character='%c', from server\n", ch);

    if (sock_fd)
        close (sock_fd);

    return (0);
}
