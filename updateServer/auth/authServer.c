
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
#include <string.h>

#include "sock.h"

int main (int argc, char** argv)
{
    int server_fd, client_fd;
    socklen_t server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    char authorize_flag = 0;

    if (argc != 3) {
        printf ("usage: %s <username> <password>\n", argv[0]);
        return (1);
    }
    // create socket
    if ((server_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: create socket ");
        return (1);
    }

    // reuse address
    int opt = 1;
    setsockopt (server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt));

    // fill server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl (INADDR_ANY);
    server_address.sin_port = htons (4231);
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

        printf ("server waiting...\n");

        client_len = sizeof (client_address);
        if ((client_fd = accept (server_fd, (struct sockaddr*) &client_address, \
                        &client_len)) < 0) {
            perror ("oops: accept ");
            return (1);
        }

        sAuthInfo* authInfo;
        char recv_buff[128];
        int read_count = 0;

        // fork for multi-clients
        if (fork () == 0) {
            if (server_fd)
                close (server_fd);

            (void) memset (recv_buff, 0x00, sizeof (recv_buff));
            read_count = recv_v (client_fd, recv_buff, 128);
            if (read_count <= 0) {
                close (client_fd);
                return (0);
            }
            authInfo = (sAuthInfo*) &recv_buff[0];

            printf ("username = %s\n", authInfo->username);
            printf ("password = %s\n", authInfo->password);
            if ((strcmp (authInfo->username, argv[1]) == 0) &&
                (strcmp (authInfo->password, argv[2]) == 0))
                authorize_flag = 1;
            else
                authorize_flag = 0;
            send_v (client_fd, &authorize_flag, 1);
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
