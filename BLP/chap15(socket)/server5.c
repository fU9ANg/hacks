
// multi-clients with select() syscall
// 2012, 2013 
// by fU9ANg

// bb.newlife@gmail.com

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/select.h>

int main (int argc, char** argv)
{
    int server_fd, client_fd;
    socklen_t server_len, client_len;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int result;
    fd_set readfds, testfds;

    // create a socket fd
    if ((server_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: socket() ");
        return (1);
    }

    // fill address and bind to socket-fd
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl (INADDR_ANY);
    server_addr.sin_port = htons (9999);
    server_len = sizeof (server_addr);

    if (bind (server_fd, (struct sockaddr*) &server_addr, server_len) < 0) {
        perror ("oops: bind() ");
        return (1);
    }

    // create listen queue, and go to listening...
    if (listen (server_fd, 5) < 0) {
        perror ("oops: listen() ");
        return (1);
    }

    // initialize read fds array and add server-fd to that..
    FD_ZERO (&readfds);
    FD_SET (server_fd, &readfds);

    // loop and accept request from clients
    while (1) {
        char ch;
        int fd;
        int nread;
        testfds = readfds;

        printf ("server waiting...\n");
        result = select (FD_SETSIZE, &testfds, (fd_set*)NULL, (fd_set*)NULL, (struct timeval*)0);
        if (result < 1) {
            perror ("server5(multi-clients and server)");
            return (1);
        }

        // check fd, if already then goto accpet request from client
        for (fd=0; fd < FD_SETSIZE; fd++) {
            if (FD_ISSET (fd, &testfds)) {
                // is listen-fd
                if (fd == server_fd) {
                    client_len = sizeof (client_addr);
                    client_fd = accept (server_fd, (struct sockaddr*) &client_addr, &client_len);
                    FD_SET (client_fd, &readfds);
                    printf ("adding client on fd: %d\n", client_fd);
                }
                // is client-fd
                else {
                    ioctl (fd, FIONREAD, &nread);
                    if (nread == 0) {
                        close (fd);
                        FD_CLR (fd, &readfds);
                        printf ("removing client on fd: %d\n", fd);
                    }
                    else {
                        read (fd, &ch, 1);
                        sleep (2);
                        printf ("serving client on fd: %d\n", fd);
                        ch++;
                        write (fd, &ch, 1);
                    }
                }
            }
        }
    }

    return (0);
}
