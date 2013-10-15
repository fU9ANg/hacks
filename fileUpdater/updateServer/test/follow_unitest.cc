
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
#include <limits.h>
#include "gtest/gtest.h"
#include "protocol.h"

#define   STR_MAX   512
#define SERVER_IP "192.168.0.166"
#define SERVER_PORT 9999

TEST(XXX, GetGourseDBCount) {
    int fd;
    struct sockaddr_in inaddr;
    char buffer[STR_MAX];

    fd = socket (PF_INET, SOCK_STREAM, 0);
    EXPECT_TRUE(fd > 0);

    inaddr.sin_family = AF_INET;
    inet_pton (AF_INET, SERVER_IP, &inaddr.sin_addr.s_addr);
    inaddr.sin_port = htons (SERVER_PORT);

    EXPECT_TRUE( 0 == connect (fd, (struct sockaddr*) &inaddr, sizeof (struct sockaddr)));

    MSG_HEAD head;
    head.cLen = sizeof (MSG_HEAD);
    head.cType = CT_GetCourseDBCount;
    memcpy (buffer, &head, sizeof (head));

    send (fd, buffer, head.cLen, 0);

    memset (buffer, 0x00, STR_MAX);

    if (recv (fd, buffer, STR_MAX, 0) < 0) {
        printf ("ERROR: in recv ()\n");
    }

    struct sDBCount c;
    memcpy (&c, buffer + sizeof (MSG_HEAD), sizeof (struct sDBCount));
    printf ("count = %d\n", c.count);

    close(fd);
}

TEST(XXX, GetAllStudentInfo) {

    int fd;
    struct sockaddr_in inaddr;
    char buffer[STR_MAX];
    fd = socket (PF_INET, SOCK_STREAM, 0);
    EXPECT_TRUE( 0 != fd);


    inaddr.sin_family = AF_INET;
    inet_pton (AF_INET, SERVER_IP, &inaddr.sin_addr.s_addr);
    inaddr.sin_port = htons (SERVER_PORT);

    EXPECT_TRUE ( 0 ==connect (fd, (struct sockaddr*) &inaddr, sizeof (struct sockaddr)));

    MSG_HEAD head;
    head.cLen = sizeof (MSG_HEAD);
    head.cType = CT_GetAllStudentInfo;
    memcpy (buffer, &head, sizeof (head));

    send (fd, buffer, head.cLen, 0);

    memset (buffer, 0x00, STR_MAX);

    /*
    p ((struct sDBCount*) (((MSG_HEAD*)pbuf->ptr()) -> cData ()))->count
    */

    int iResult = 0;
    int iLen = 0;
    while (1) {
        memset (buffer, 0x00, STR_MAX);

        iResult = recv (fd, buffer, sizeof (int), 0);
        if (iResult != sizeof (int)) {
            printf ("ERROR: in recv ()\n");
            break;
        }
        else {
            memcpy (&iLen, buffer, sizeof (int));
            iResult = recv (fd, buffer+sizeof (int), iLen - sizeof (int), 0);
            if (iResult != (iLen - sizeof (int))) {
                printf ("ERROR: in recv ()\n");
                break;
            }
            else {
                MSG_HEAD* p_head = (MSG_HEAD*)buffer;
                printf ("len = %d, type=%d\n", p_head->cLen, p_head->cType);
                if (ST_GetDBRecordFinished == p_head->cType) {
                    printf("package over\n");
                    break;
                }
            }
        }
    }
    close (fd);
    fd = 0;
}

TEST(XXX, GetCourseItemKeyInfoReq) {
    int fd;
    struct sockaddr_in inaddr;
    char buffer[STR_MAX];

    if ((fd = socket (PF_INET, SOCK_STREAM, 0)) < 0) {
        printf ("error: in socket ()\n");
        return;
    }

    inaddr.sin_family = AF_INET;
    inet_pton (AF_INET, "192.168.0.166", &inaddr.sin_addr.s_addr);
    inaddr.sin_port = htons (9999);

    if (connect (fd, (struct sockaddr*) &inaddr, sizeof (struct sockaddr)) < 0) {
        printf ("error: in connnnnnnnnnnnect ()\n");
        if (fd) close (fd);
            return;
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
    //recv (fd, buffer + sizeof(MSG_HEAD), p_head->cLen - sizeof(MSG_HEAD), 0 );
    int readlen = read (fd, buffer + sizeof(MSG_HEAD), p_head->cLen - sizeof(MSG_HEAD));
    printf("%d\n", readlen);

    GetCourseItemKeyInfoRsp t_rsp;
    memcpy(&t_rsp, p_head->cData(), sizeof(GetCourseItemKeyInfoRsp));

    printf ("recvice from server:\n");
    printf("[%s]\n", t_rsp.keys);
    memset (buffer, 0x00, STR_MAX);
    close (fd);
}
