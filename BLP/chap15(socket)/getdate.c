
// by fU9ANg

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char** argv)
{
    char* host;
    int socket_fd;
    int len, result;
    struct sockaddr_in address;
    struct hostent *hostinfo;
    struct servent *servinfo;
    char buffer[128];

    host = (argc == 1) ? "localhost" : argv[1];

    // get host information
    if (!(hostinfo = gethostbyname (host))) {
        fprintf (stderr, "no host: %s\n", host);
        return (1);
    }

    // get daytime server by name
    if (!(servinfo = getservbyname ("daytime", "tcp"))) {
        fprintf (stderr, "no daytime service on the OS\n");
        return (1);
    }

    // print port of daytime
    printf ("daytime port is %d\n", ntohs (servinfo->s_port));

    // create inet socket for daytime server
    if ((socket_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: getdate-socket ");
        return (1);
    }

    // fill data-struct for daytime server
    address.sin_family = AF_INET;
    address.sin_port = servinfo->s_port;
    address.sin_addr = *(struct in_addr*) *hostinfo->h_addr_list;
    len = sizeof (address);

    // try connection
    if ((result = connect (socket_fd, (struct sockaddr*) &address, len)) < 0) {
        perror ("oops: getdate-connect ");
        return (1);
    }

    // read date-time from daytime server
    result = read (socket_fd, buffer, sizeof (buffer));
    buffer[result] = 0x00;
    printf ("read %d bytes: %s", result, buffer);

    if (socket_fd)
        close (socket_fd);

    return (0);
}
