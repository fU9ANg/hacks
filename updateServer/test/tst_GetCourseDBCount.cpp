

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include "protocol.h"

#define   STR_MAX   512

int main (void)
{

    int fd;
    struct sockaddr_in inaddr;
    char buffer[STR_MAX];

    if ((fd = socket (PF_INET, SOCK_STREAM, 0)) < 0) {
        printf ("error: in socket ()\n");
        return (1);
    }

    inaddr.sin_family = AF_INET;
    inet_pton (AF_INET, "222.186.50.76", &inaddr.sin_addr.s_addr);
    inaddr.sin_port = htons (9999);

    if (connect (fd, (struct sockaddr*) &inaddr, sizeof (struct sockaddr)) < 0) {
        printf ("error: in connnnnnnnnnnnect ()\n");
        if (fd) close (fd);
        return (1);
    }

    MSG_HEAD head;
    head.cLen = sizeof (MSG_HEAD);
    head.cType = CT_GetCourseDBCount;
    memcpy (buffer, &head, sizeof (head));

    send (fd, buffer, head.cLen, 0);

#if 1
    printf ("recvice from server:\n");
    memset (buffer, 0x00, STR_MAX);

    /*
    p ((struct sDBCount*) (((MSG_HEAD*)pbuf->ptr()) -> cData ()))->count
    */
#if 1
    if (recv (fd, buffer, STR_MAX, 0) < 0) {
        printf ("ERROR: in recv ()\n");
        if (fd) close (fd);
        return (1);
    }
#endif
    //read (fd, buffer, STR_MAX);
    //MSG_HEAD* p = (MSG_HEAD *) buffer;
    struct sDBCount c;
    memcpy (&c, buffer + sizeof (MSG_HEAD), sizeof (struct sDBCount));
    printf ("len = %d\n", c.count);

#endif
    if (fd)
        close (fd);
    return (0);
}
