
/*
 * Written 2013 by fU9ANg
 * bb.newlife@gmail.com
 */

#ifndef _CHAT_DEFINE_H
#define _CHAT_DEFINE_H

#define SERVER_PORT     7000
#define MAX_LISTEN      20

#define FD_SETSIZE      1000

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define CLOSESOCKET(sock)   close(sock);
#define INVALID_SOCKET      (-1)
#define TRUE  1
#define FALSE 0

/* redefine data type */
typedef int      SOCKET;
typedef int      BOOL;
typedef unsigned char  BYTE;
typedef unsigned long  DWORD;
typedef unsigned short WORD;

#endif  // _CHAT_DEFINE_H
