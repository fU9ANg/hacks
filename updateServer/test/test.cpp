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
#define STUDENT_COUNT 2

void set_clasroom(int fd);

void* teacher_thread(void* p);
void* student_thread(void* p);

int main(int argc, char* argv[]){
    pthread_t pid_teacher = 0;
    pthread_t pid_student[STUDENT_COUNT] = {0};

//    pthread_create(&pid_teacher, NULL, teacher_thread, NULL);

    for(int i = 0; i < STUDENT_COUNT; ++i) {
        pthread_create(&pid_student[i], NULL, student_thread, NULL);
    }

//    pthread_join(pid_teacher, NULL);
    for(int i = 0; i < STUDENT_COUNT; ++i) {
        pthread_join(pid_student[i], NULL);
    }
    return 0;
}


void* teacher_thread(void* p) {
    int cntFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERV_IP);
    addr.sin_port = htons(SERV_PORT);

    connect(cntFd, (struct sockaddr*)&addr, sizeof(struct sockaddr));
    char buf[1024] = {0};

    MSG_HEAD head;
    struct sLogin loginreq;
    loginreq.type = MCT_TEACHER;

    snprintf(loginreq.username, sizeof(loginreq.username), "%s", "张三");
    snprintf(loginreq.password, sizeof(loginreq.password), "%s", "123456");

    head.cLen = sizeof(MSG_HEAD) + sizeof(struct sLogin);
    head.cType = CT_Login;
    memcpy(buf, &head, sizeof(MSG_HEAD));
    memcpy(buf + sizeof(MSG_HEAD), &loginreq, sizeof(struct sLogin));
    send( cntFd, buf, head.cLen, 0);

    memset(buf, '\0', 1024);

    recv(cntFd, buf, 1024, 0);
                    //CT_LoginReuslt
    MSG_HEAD* x = (MSG_HEAD*)buf;

    struct sLoginOutResult loginresp;
    memcpy(&loginresp, buf + sizeof(MSG_HEAD), sizeof(loginresp));
    printf("teacher %d  %s\n", loginresp.succeed, loginresp.message);

    close(cntFd);
    return NULL;
}
void* student_thread(void* p) {
    int cntFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERV_IP);
    addr.sin_port = htons(SERV_PORT);

    connect(cntFd, (struct sockaddr*)&addr, sizeof(struct sockaddr));

    set_clasroom(cntFd);

    char buf[1024] = {0};

    MSG_HEAD head;
    struct sLogin loginreq;
    memset(&loginreq, 0x00, sizeof(struct sLogin));
    loginreq.type = MCT_STUDENT;

    snprintf(loginreq.username, sizeof(loginreq.username), "%s", "26");
    snprintf(loginreq.password, sizeof(loginreq.password), "%s", "123456");

    head.cLen = sizeof(MSG_HEAD) + sizeof(struct sLogin);
    head.cType = CT_Login;
    memcpy(buf, &head, sizeof(MSG_HEAD));
    memcpy(buf + sizeof(MSG_HEAD), &loginreq, sizeof(struct sLogin));
    send( cntFd, buf, head.cLen, 0);

    memset(buf, '\0', 1024);

    recv(cntFd, buf, 1024, 0);
                    //CT_LoginReuslt
    MSG_HEAD* x = (MSG_HEAD*)buf;

    struct sLoginOutResult loginresp;
    memcpy(&loginresp, buf + sizeof(MSG_HEAD), sizeof(loginresp));
    printf("student %d  %s\n", loginresp.succeed, loginresp.message);

    close(cntFd);
    return NULL;
}

void set_clasroom(int fd) {
    char buf[1024] = {0};
    MSG_HEAD head;
    TSelectedClassRoom body;
    head.cType = CT_SelectedClassRoom;
    head.cLen = sizeof(head) + sizeof(body);
    body.classroom_id = 2;
    body.client_type = MCT_STUDENT;
    memcpy(buf, &head, sizeof(head));
    memcpy(buf + sizeof(head), &body, sizeof(body));
    send(fd, buf, head.cLen, 0);
    return;
}
