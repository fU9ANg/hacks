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


#include "protocol.h"
#define SERV_IP "192.168.0.166"
#define SERV_PORT 9999 
#define STUDENT_COUNT 1

void set_clasroom(int fd);

void* student_thread(void* p);

int main(int argc, char* argv[]){
    int cntFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERV_IP);
    addr.sin_port = htons(SERV_PORT);
    connect(cntFd, (struct sockaddr*)&addr, sizeof(struct sockaddr));

    set_clasroom(cntFd);
    char buf[1024];
    while(true) {
        memset(buf, 0x00, sizeof(buf));
        recv(cntFd, buf, 1024, 0);
        MSG_HEAD* p = (MSG_HEAD*)buf;
        printf("TYPE = [%d]\n", p->cType);
    }

    close(cntFd);
    return 0;
}

void set_clasroom(int fd) {
    char buf[1024] = {0};
    MSG_HEAD head;
    TSelectedClassRoom body;
    head.cType = CT_SelectedClassRoom;
    head.cLen = sizeof(head) + sizeof(body);
    body.classroom_id = 1;
    body.client_type = MCT_WHITEBOARD;
    memcpy(buf, &head, sizeof(head));
    memcpy(buf + sizeof(head), &body, sizeof(body));
    send(fd, buf, head.cLen, 0);
    return;
}
