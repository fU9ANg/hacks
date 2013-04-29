
/*
 * Written 2013 by fU9ANg
 * bb.newlife@gmail.com
 */

#ifndef _CHAT_SOCKET_H
#define _CHAT_SOCKET_H

#include "packet.h"

void   setNonblock       (SOCKET fd);
void   acceptNewClient   (SOCKET listenfd);
SOCKET initServerSock    (int port, int backLog);
void   disconnectClient  (struct sPacket* pClient);
int    flushSendBuff     (struct sPacket* pClient);
BOOL   recvFromClient    (struct sPacket* pClient);
void   sendData  (struct sPacket* pClient, const char* data, int size);
void   sendToAll (const char* data, int size);

#endif  // _CHAT_SOCKET_H
