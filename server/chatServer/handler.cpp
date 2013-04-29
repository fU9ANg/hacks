
#include "define.h"
#include "socket.h"
#include "packet.h"
#include "list.h"
#include "utils.h"
#include "handler.h"

void PACKET_AliveCheck (struct sPacket* pClient)
{
}

void PACKET_ChangeNick (struct sPacket* pClient)
{
    char nick[64];
    GetString (pClient->m_recvBuff, nick, pClient->m_recvPos);
    strcpy (pClient->m_name, nick);
}

void PACKET_RecvMsg (struct sPacket* pClient)
{
    char msg[MAX_SOCK_BUFF];

    GetString (pClient->m_recvBuff, msg, pClient->m_recvPos);
    int packetPos;
    char packet[MAX_SOCK_BUFF];
    char tmp[MAX_SOCK_BUFF];

    sprintf (tmp, "%s : %s\r\n", pClient->m_name, msg);

    packetPos = 2;
    PutWord (packet, PACKET_SEND_MSG, packetPos);
    PutString (packet, tmp, packetPos);
    PutSize (packet, packetPos);

    sendToAll (packet, packetPos);
}

BOOL readRecvBuff (struct sPacket* pClient)
{
    WORD msgSize;
    WORD tag;

    while (pClient->m_recvSize > 0)
    {
        pClient->m_recvPos = 0;

        msgSize = GetWord (pClient->m_recvBuff, pClient->m_recvPos);
        tag = GetWord (pClient->m_recvBuff, pClient->m_recvPos);

        if (pClient->m_recvSize < msgSize)
            return (1);

        switch (tag)
        {
            case PACKET_ALIVE_CHECK:
                PACKET_AliveCheck (pClient);
                break;
            case PACKET_CHANGE_NICK:
                PACKET_ChangeNick (pClient);
                break;
            case PACKET_RECV_MSG:
                PACKET_RecvMsg (pClient);
                break;
            case PACKET_SEND_MSG:
                break;
        }

        (void) memmove (&pClient->m_recvBuff[0], \
                        &pClient->m_recvBuff[msgSize], \
                         pClient->m_recvSize - msgSize);

        pClient->m_recvSize -= msgSize;
    }
    return (1);
}
