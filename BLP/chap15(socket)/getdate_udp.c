
// 2012, by fU9ANg
// call udp server of daytime

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
    socklen_t len, result;
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

    // check that the daytime service exists on the host
    if (!(servinfo = getservbyname ("daytime", "udp"))) {       // modify "tcp" to "udp"
        fprintf (stderr, "no daytime service on the OS\n");
        return (1);
    }

    // print port of daytime
    printf ("daytime port is %d\n", ntohs (servinfo->s_port));

    // create a UDP socket
    if ((socket_fd = socket (AF_INET, SOCK_DGRAM, 0)) < 0) {    // modify SOCK_STREAM to SOCK_DGRAM
        perror ("oops: getdate-socket ");
        return (1);
    }

    // construct the address for use with sendto/recvfrom... syscall
    address.sin_family = AF_INET;
    address.sin_port = servinfo->s_port;
    address.sin_addr = *(struct in_addr*) *hostinfo->h_addr_list;
    len = sizeof (address);

    // read date-time from daytime server
    result = sendto (socket_fd, buffer, 1, 0, (struct sockaddr*) &address, len);      // modify
    result = recvfrom (socket_fd, buffer, sizeof (buffer), 0, (struct sockaddr*) &address, &len); // modify
    buffer[result] = 0x00;
    printf ("read %d bytes: %s", result, buffer);

    if (socket_fd)
        close (socket_fd);

    return (0);
}
