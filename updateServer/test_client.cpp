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
#include <pthread.h>
#include <string>
#include <iostream>

#include "protocol.h"
#include "Sock.h"
#include "updatecontent.pb.h"
#include "version.pb.h"

#define SERV_IP        "192.168.0.254"
#define SERV_PORT       15432
#define STUDENT_COUNT   2
#define MAX_BUF_SIZE    9000 

using namespace std;

int main(int argc, char* argv[])
{
    int cntFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERV_IP);
    addr.sin_port = htons(SERV_PORT);

    connect(cntFd, (struct sockaddr*)&addr, sizeof(struct sockaddr));
    char buf[MAX_BUF_SIZE] = {0};

    // send CT_Login
    (void) memset (buf, 0x00, MAX_BUF_SIZE);
    MSG_HEAD* head = (MSG_HEAD*) buf;
    head->cLen = MSG_HEAD_LEN;
    head->cType = CT_Login;
    send_v (cntFd, buf, head->cLen);

    // send CT_GetVersion
    (void) memset (buf, 0x00, MAX_BUF_SIZE);
    version v;
    v.set_ver ("v1.2");
    string  s_version;
    v.SerializeToString (&s_version);
    head = (MSG_HEAD*) buf;
    head->cLen = MSG_HEAD_LEN + s_version.size ();
    head->cType = CT_GetVersion;
    (void) memcpy (head->cData(), s_version.c_str (), s_version.size ());
    send_v (cntFd, buf, head->cLen);

    // send CT_GetUpdateContent
    (void) memset (buf, 0x00, MAX_BUF_SIZE);
    head = (MSG_HEAD*) buf;
    head->cLen = MSG_HEAD_LEN;
    head->cType = CT_GetUpdateContent;
    send_v (cntFd, buf, head->cLen);
#if 1
    updatecontent update;
    (void) memset (buf, 0x00, MAX_BUF_SIZE);
    recv_v (cntFd, buf, MSG_HEAD_LEN);
    unsigned int recv_len = *(int*) ((char*)buf);
    recv_v (cntFd, buf, recv_len-MSG_HEAD_LEN);
    s_version = buf;
    update.ParseFromString (s_version);
    cout << "xml content is:\n" << update.xmlcontent () << "" << endl;
#endif

    if (cntFd) close (cntFd);
    return 0;
}
