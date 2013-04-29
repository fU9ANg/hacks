
/*
 * Written 2013 by fU9ANg
 * bb.newlife@gmail.com
 */

#ifndef _CHAT_PACKET_H
#define _CHAT_PACKET_H

#define MAX_SOCK_BUFF   1024
#define NAME_LEN        50
#define IP_LEN          20

struct sPacket
{
    SOCKET          m_sock;
    char            m_ip[IP_LEN];

    char            m_recvBuff[MAX_SOCK_BUFF];
    int             m_recvSize;
    int             m_recvPos;

    char            m_sendBuff[MAX_SOCK_BUFF];
    int             m_sendSize;

    char            m_name[NAME_LEN];

    DWORD           m_lastRecvTime;

    struct sPacket* m_prev;
    struct sPacket* m_next;
};

#endif  //_CHAT_PACKET_H
