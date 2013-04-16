

// 2013 by fU9ANg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main (int argc, char** argv)
{
    int sock_fd;
    int len;
    struct sockaddr_un address;
    int result;
    char ch = 'A';

    if ((sock_fd = socket (AF_UNIX, SOCK_STREAM, 0)) < 0) {
        perror ("oops: socket ");
        return (1);
    }

    (void) memset (&address, 0x00, sizeof (struct sockaddr_un));
    address.sun_family = AF_UNIX;
    strcpy (address.sun_path, "server_socket");
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
