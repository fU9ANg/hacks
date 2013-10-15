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
#define SERV_IP "192.168.0.166"
#define SERV_PORT 9999 
void login(int fd);
void loginclassroom(int fd);
void send_ST_Puzzle_GameStart(int fd);
void send_ST_Puzzle_GameStop(int fd);

int main(int argc, char* argv[]){
    int cntFd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERV_IP);
    addr.sin_port = htons(SERV_PORT);

    connect(cntFd, (struct sockaddr*)&addr, sizeof(struct sockaddr));

    //login(cntFd);
    loginclassroom(cntFd);
 //   sleep(3);
//    send_CT_ShowSpriteAnimation(cntFd);
  //  sleep(100);
  //
    sleep(1);
    send_ST_Puzzle_GameStart(cntFd);

    send_ST_Puzzle_GameStop(cntFd);

    char buf[1024] = {0};
    while(true) {
        memset(buf, 0x00, sizeof(buf));
        recv(cntFd, buf, 1024, 0);
        MSG_HEAD* p_head = (MSG_HEAD*)buf;
        printf("CType = [%d]\n", p_head->cType);
        if (p_head->cType == ST_SendStudentStatus) {
            TSendStudentStatusReq req;
            memcpy(&req, p_head->cData(), sizeof(req));
            printf("id = %08x   status = %08x\n", req.student_id, req.status);
        }
    }

    close(cntFd);
    return 0;
}

void login(int fd) {
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
    send( fd, buf, head.cLen, 0);

    memset(buf, '\0', 1024);

    recv(fd, buf, 1024, 0);
                    //CT_LoginReuslt
    MSG_HEAD* x = (MSG_HEAD*)buf;

    struct sLoginOutResult loginresp;
    memcpy(&loginresp, buf + sizeof(MSG_HEAD), sizeof(loginresp));
    printf("%d  %s\n", loginresp.succeed, loginresp.message);
}

void loginclassroom(int fd) {
    char buf[1024] = {0};
    MSG_HEAD head;
    head.cLen = sizeof(MSG_HEAD) + sizeof(struct sLoginOutClassRoom);
    head.cType = CT_LoginClassRoom;

    struct sLoginOutClassRoom loginclassroom;
    
    snprintf(loginclassroom.sTeacherName,sizeof(loginclassroom.sTeacherName), "%s","");
    snprintf(loginclassroom.sClassName, sizeof(loginclassroom.sClassName), "%s", "A教室");
    snprintf(loginclassroom.sClassRoomName, sizeof(loginclassroom.sClassRoomName), "%s", "A教室");

    memcpy(buf, &head, sizeof(MSG_HEAD));
    memcpy(buf + sizeof(MSG_HEAD), &loginclassroom, sizeof(struct sLoginOutClassRoom));
    send( fd, buf, head.cLen, 0);
}

void send_ST_Puzzle_GameStart(int fd){
    MSG_HEAD head;
    head.cLen = sizeof(MSG_HEAD) + sizeof(struct sJigsawInitData);
    head.cType = CT_Puzzle_GameStart;
    struct sJigsawInitData body;
    body.rowCount = 3;
    body.columnCount = 3;
    strcpy(body.picturePath, "http://d.lanrentuku.com/down/png/1001/I_like_buttons/CuteBall-Favorites000.png");

    char buf[1024];
    memcpy(buf, &head, sizeof(MSG_HEAD));
    memcpy(buf + sizeof(MSG_HEAD), &body, sizeof(body));

    send(fd, buf, head.cLen, 0);
}

void send_ST_Puzzle_GameStop(int fd){
    MSG_HEAD head;
    head.cLen = sizeof(MSG_HEAD);
    head.cType = CT_Puzzle_EndGame;
    send(fd, &head, head.cLen, 0);
}
