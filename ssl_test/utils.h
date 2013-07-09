
#ifndef _SSL_UTILS_H
#define _SSL_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFF_SIZE   2048 

extern SSL_CTX* init_ssl_library (char* c_file = NULL, char* p_file = NULL, int flag = 0);
extern void dump_centificate (SSL* ssl);

#endif  // _SSL_UTILS_H
