
// by fU9ANg
// @2013

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main (int argc, char** argv)
{
    int server_fd, client_fd;
    socklen_t server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    // create socket
    if ((server_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: create socket ");
        return (1);
    }

    // fill server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl (INADDR_ANY);
    server_address.sin_port = htons (9999);
    server_len = sizeof (server_address);

    // bind address to socket-fd
    if (bind (server_fd, (struct sockaddr*) &server_address, server_len) < 0) {
        perror ("oops: bind ");
        return (1);
    }

    // create queue and listen
    if (listen (server_fd, 5)) {
        perror ("oops: listen ");
        return (1);
    }

    // set handler to default action of signal number is SIGCHLD
    signal (SIGCHLD, SIG_IGN);

    while (1) {
        char ch;

        printf ("server waiting...\n");

        client_len = sizeof (client_address);
        if ((client_fd = accept (server_fd, (struct sockaddr*) &client_address, \
                        &client_len)) < 0) {
            perror ("oops: accept ");
            return (1);
        }

        // fork for multi-clients
        if (fork () == 0) {
            read (client_fd, &ch, 1);
            sleep (2);
            ch++;
            write (client_fd, &ch, 1);
            if (client_fd)
                close (client_fd);
            return (0);
        }
        else {
            if (client_fd)
                close (client_fd);
        }
    }

    return (0);
}
