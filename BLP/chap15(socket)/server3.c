

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
    int server_fd, client_fd;
    socklen_t server_len, client_len;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int result;

    // create inet socket
    if ((server_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: socket ");
        return (1);
    }

    // fill address of server
    (void) memset (&server_address, 0x00, sizeof (struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl (INADDR_ANY);    // modify base server2.c
    server_address.sin_port = htons (9999);                 // modify base server2.c
    server_len = sizeof (server_address);

    // bind address to socket-fd
    if ((result = bind (server_fd, (struct sockaddr*) &server_address, server_len)) < 0) {
        perror ("oops: bind ");
        return (1);
    }

    // create listen-queue and listening...
    if ((result = listen (server_fd, 5)) < 0) {
        perror ("oops: listen ");
        return (1);
    }

    // recv message, process and send data to client
    while (1) {
        char ch;
        printf ("server waiting...\n");
        client_len = sizeof (client_address);
        if ((client_fd = accept (server_fd, \
            (struct sockaddr*) &client_address, &client_len)) < 0) {
            perror ("oops: accept ");
            return (1);
        }
        read (client_fd, &ch, 1);
        ch++;
        write (client_fd, &ch, 1);

        if (client_fd)
            close (client_fd);
    }

    return (0);
}
