
#include "define.h"
#include "socket.h"
#include "packet.h"
#include "list.h"
#include "utils.h"
#include "handler.h"

/*
====================
 check client is alive?
====================
 */
void handleAliveCheck (struct sPacket* pClient)
{
}

/*
====================
 change nick of client
====================
 */
void handleChangeNick (struct sPacket* pClient)
{
    char nick[64];
    getString (pClient->m_recvBuff, nick, pClient->m_recvPos);
    strcpy (pClient->m_name, nick);
}

/*
====================
 receive client message packet
====================
 */
void handleRecvMsg (struct sPacket* pClient)
{
    char msg[MAX_SOCK_BUFF];

    getString (pClient->m_recvBuff, msg, pClient->m_recvPos);
    int  packetPos;
    char packet[MAX_SOCK_BUFF];
    char tmp[MAX_SOCK_BUFF];

    sprintf (tmp, "%s : %s\r\n", pClient->m_name, msg);

    packetPos = 2;
    putWord (packet, PACKET_SEND_MSG, packetPos);
    putString (packet, tmp, packetPos);
    putSize (packet, packetPos);

    sendToAll (packet, packetPos);
}

/*
====================
 handle receive buffer
====================
 */
BOOL readRecvBuff (struct sPacket* pClient)
{
    WORD msgSize;
    WORD tag;

    while (pClient->m_recvSize > 0)
    {
        pClient->m_recvPos = 0;

        msgSize = getWord (pClient->m_recvBuff, pClient->m_recvPos);
        tag     = getWord (pClient->m_recvBuff, pClient->m_recvPos);

        if (pClient->m_recvSize < msgSize)
            return (1);

        switch (tag)
        {
            case PACKET_ALIVE_CHECK:
                handleAliveCheck (pClient);
                break;
            case PACKET_CHANGE_NICK:
                handleChangeNick (pClient);
                break;
            case PACKET_RECV_MSG:
                handleRecvMsg (pClient);
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
