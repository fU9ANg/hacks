
//
// @2013
// by fU9ANg
//

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>

int main (int argc, char** argv)
{
    char *host, **names, **addrs;
    struct hostent* hostinfo;

    char myname[255];
    gethostname (myname, 255);

    host = (argc == 1) ? myname : argv[1];

    if (!(hostinfo = gethostbyname (host))) {
        fprintf (stderr, "can't get information for host: %s\n", host);
        return (1);
    }

    // get host name and alias name
    printf ("results for host: %s\n", host);
    printf ("Name: %s\n", hostinfo->h_name);
    printf ("Aliases:");
    names = hostinfo->h_aliases;
    while (*names) {
        printf (" %s", *names);
        names++;
    }
    printf ("\n");

    if (hostinfo->h_addrtype != AF_INET) {
        fprintf (stderr, "not an IP host!\n");
        return (1);
    }

    // get inet address
    addrs = hostinfo->h_addr_list;
    while (*addrs) {
        printf (" %s", inet_ntoa (* (struct in_addr*) *addrs));
        addrs++;
    }
    printf ("\n");

    return (0);
}
