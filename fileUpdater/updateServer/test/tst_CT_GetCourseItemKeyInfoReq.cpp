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
    inet_pton (AF_INET, "192.168.0.166", &inaddr.sin_addr.s_addr);
    inaddr.sin_port = htons (9999);

    if (connect (fd, (struct sockaddr*) &inaddr, sizeof (struct sockaddr)) < 0) {
        printf ("error: in connnnnnnnnnnnect ()\n");
        if (fd) close (fd);
        return (1);
    }

    MSG_HEAD head;
    head.cLen = sizeof (MSG_HEAD) + sizeof(unsigned int);
    head.cType = CT_GetCourseItemKeyInfoReq;
    memcpy (buffer, &head, sizeof (head));
    unsigned int item_id = 10;
    memcpy(buffer + sizeof(head), &item_id, sizeof(unsigned int));

    send (fd, buffer, head.cLen, 0);

    memset(buffer, 0x00, sizeof(buffer));

    recv (fd, buffer, sizeof(MSG_HEAD), 0);
    MSG_HEAD* p_head = (MSG_HEAD*)buffer;
    recv (fd, buffer + sizeof(MSG_HEAD), p_head->cLen - sizeof(MSG_HEAD), 0 );

    GetCourseItemKeyInfoRsp t_rsp;
    memcpy(&t_rsp, p_head->cData(), sizeof(GetCourseItemKeyInfoRsp));

    printf ("recvice from server:\n");
    printf("[%s]\n", t_rsp.keys);
    memset (buffer, 0x00, STR_MAX);

    close (fd);
    return (0);
}
