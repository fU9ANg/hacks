#include "Sock.h"

ssize_t send_n(int fd,
        void* buf,
        ssize_t left,
        struct timeval* timeout){
    if (NULL == buf || NULL == timeout){
        return -1;
    }

    ssize_t recved = 0;
    fd_set st;
    while(0 != left) {
        FD_ZERO(&st);
        FD_SET(fd, &st);
        int i = select(fd + 1, NULL, &st, NULL, timeout);
        if (0 >= i) {
            break;
        } else {
            ssize_t len = send(fd, buf + recved, left, 0);
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            recved += len;
        }
    }
    return 0;
}

ssize_t recv_n(int fd,
        void* buf,
        ssize_t left,
        struct timeval* timeout){
    if (NULL == buf || NULL == timeout){
        return -1;
    }
    ssize_t recved = 0;
    fd_set st;
    while(0 != left){
        FD_ZERO(&st);
        FD_SET(fd, &st);
        int i = select(fd + 1, &st, NULL, NULL, timeout);
        if (0 >= i) {
            break;
        } else {
            ssize_t len = recv(fd, buf + recved, left, 0);
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            recved += len;
        }
    }
    return recved;
}

int send_v(int fd,
        void* buf,
        ssize_t left){
    if (NULL == buf){
        return -1;
    }

    int sended = 0;
    int len = 0;
    while(0 != left) {
            len = send(fd, buf + sended, left, 0);
#if 1
            if (len <= 0) {
                if ((errno == EAGAIN) || (errno == EINTR)) {
                    if (len < 0) {
                        len = 0;
                        continue;
                    }
                }
                else {
                    break;
                }
            }
#else
            if (EAGAIN == errno) {
                usleep (100);
                continue;
            }
            if (errno == EINTR) {
                usleep (100);
                continue;
            }
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
#endif
            left -= len;
            sended += len;
    }
    return sended;
}

int recv_v(int fd,
        void* buf,
        ssize_t left){
    if (NULL == buf){
        return -1;
    }

    int recved = 0;
    int len = 0;
    while(0 != left) {
            len = recv(fd, (char*)buf + recved, left, 0);
#if 1
            if (len <= 0) {
                if ((EAGAIN == errno) || (EINTR == errno)) {
                    if (len < 0) {
                        len = 0;
                        continue;
                    }
                }
                else {
                    break;
                }
            }

            left -= len;
            recved += len;
#else
            if (EAGAIN == errno) {
                usleep (100);
                continue;
            }
            if (errno == EINTR) {
                usleep (100);
                continue;
            }
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
#endif
            left -= len;
            recved += len;
    }
    return recved;
}
