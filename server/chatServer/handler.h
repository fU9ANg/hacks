
/*
 * Written 2013 by fU9ANg
 * bb.newlife@gmail.com
 */

#ifndef _CHAT_HANDLER_H
#define _CHAT_HANDLER_H

#include "packet.h"

#define PACKET_ALIVE_CHECK     0
#define PACKET_CHANGE_NICK     1
#define PACKET_RECV_MSG        2
#define PACKET_SEND_MSG        3

BOOL readRecvBuff (struct sPacket* pClient);

#endif  //_CHAT_HANDLER_H
