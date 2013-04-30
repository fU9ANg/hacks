
#include "define.h"
#include "packet.h"
#include "list.h"
#include "socket.h"
#include "utils.h"

extern SOCKET          g_Socket;
extern struct sPacket* g_ClientList;
extern int             g_TotalClient;

/*
====================
 set socket fd to nonblock
====================
*/
void setNonblock (SOCKET fd)
{
    int flags;
    flags = fcntl (fd, F_GETFL, 0);
    flags |= O_NONBLOCK;
    if (fcntl (fd, F_SETFL, flags) < 0)
        outLog ((char*)" * nonblock Error\r\n");
}

/*
====================
 initialize server socket
====================
*/
SOCKET initServerSock (int port, int backLog)
{
    struct sockaddr_in sa;
    SOCKET sock;
    sock = socket (PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        outLog ((char*)"InitServerSock(), socket (..) failed [PORT: %d].. \r\n", port);
        return (-1);
    }
    int opt = 1;

    if (setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, \
                   (char*) &opt, sizeof (opt)) < 0) {
        outLog ((char*)"* Error: setsockopt REUSEADDR\r\n");
        exit (1);
    }

    struct linger ld;
    ld.l_onoff = 0;
    ld.l_linger = 0;
    if (setsockopt (sock, SOL_SOCKET, SO_LINGER, \
                   (char*) &ld, sizeof (ld)) < 0)
        outLog ((char*)"* Error: setsockopt SO_LINGER ...\r\n");

    (void) memset ((char*)&sa, 0x00, sizeof (sa));
    sa.sin_family = PF_INET;
    sa.sin_port = htons (port);
    sa.sin_addr.s_addr = INADDR_ANY;

    if (bind (sock, (struct sockaddr*)&sa, sizeof (sa)) < 0)
    {
        outLog ((char*)"InitServerSock(), bind (..) failed [PORT: %d].. \r\n", port);
        CLOSESOCKET (sock);
        return (-1);
    }

    setNonblock (sock);

    listen (sock, backLog);

    return (sock);
}

/*
====================
 acppet a new client fd
====================
*/
void acceptNewClient (SOCKET listenfd)
{
    SOCKET newDesc;
    struct sockaddr_in peer;
#if defined (WIN32)
    int peersize;
#else
    socklen_t peersize;
#endif

    peersize = sizeof (peer);
    newDesc = accept (listenfd, (struct sockaddr*) &peer, &peersize);
    if (newDesc < 0)
    {
        outLog ((char*)"accept new client failed!\r\n");
        return;
    }
    setNonblock (newDesc);

    struct sPacket* newClient = (struct sPacket*) malloc (sizeof (struct sPacket*));

    if (!newClient)
    {
        CLOSESOCKET (newDesc);
        return;
    }

    newClient->m_sock = newDesc;
    (void*) strcpy (newClient->m_ip, (char*) inet_ntoa (peer.sin_addr));

    *newClient->m_recvBuff = 0x00;
     newClient->m_recvSize = 0x00;
     newClient->m_recvPos  = 0x00;

    *newClient->m_sendBuff = 0x00;
     newClient->m_sendSize = 0x00;
 
    *newClient->m_name     = 0x00;
     newClient->m_lastRecvTime = getTime ();

    newClient->m_prev = NULL;
    newClient->m_next = NULL;

    INSERT_TO_LIST (g_ClientList, newClient, m_prev, m_next);
    g_TotalClient++;
    outLog ((char*)"accept new connection: %d [%s]\r\n", newDesc, newClient->m_ip);
}

/*
====================
 dis-connection client fd
====================
*/
void disconnectClient (struct sPacket* pClient)
{
    REMOVE_FROM_LIST (g_ClientList, pClient, m_prev, m_next);
    if (pClient->m_sock != INVALID_SOCKET)
        CLOSESOCKET (pClient->m_sock);

    free (pClient);
    pClient = NULL;
}

/*
====================
 send data to buffer
====================
*/
void sendData (struct sPacket* pClient, const char* data, int size)
{
    if ((pClient->m_sendSize + size) > MAX_SOCK_BUFF)
        return;

    memcpy (&pClient->m_sendBuff[pClient->m_sendSize], data, size);

    pClient->m_sendSize += size;
}

/*
====================
 send data to all client
====================
*/
void sendToAll (const char* data, int size)
{
    struct sPacket* client = NULL;
    struct sPacket* next_client = NULL;
    LIST_WHILE (g_ClientList, client, next_client, m_next);
    sendData (client, data, size);
    LIST_WHILEEND (g_ClientList, client, next_client);
}

/*
====================
 flush send queue (buffers)
====================
*/
int flushSendBuff (struct sPacket* pClient)
{
    int sendSize;

    sendSize = send (pClient->m_sock, pClient->m_sendBuff, \
                     pClient->m_sendSize, 0);

    if (sendSize <= 0)
        return (-1);

    if (sendSize < pClient->m_sendSize)
    {
        (void*) memmove (&pClient->m_sendBuff[0],
                         &pClient->m_sendBuff[sendSize],
                          pClient->m_sendSize - sendSize);
        pClient->m_sendSize -= sendSize;
    }
    else
    {
        *pClient->m_sendBuff = 0x00;
         pClient->m_sendSize = 0x00;
    }
    return (sendSize);
}

/*
====================
 recv data from a client
====================
*/
BOOL recvFromClient (struct sPacket* pClient)
{
    int recvSize;
    char recvBuff[MAX_SOCK_BUFF];

    recvSize = recv (pClient->m_sock, recvBuff, 1024, 0);
    if (recvSize == 0)
        return (0);

    if (recvSize  < 0)
    {
#if defined (WIN32)
        if (WSAGetLastError () != WSAEWOULDBLOCK)
            return (0);
#else
        if (errno != EWOULDBLOCK)
            return (0);
#endif
        else
            return (1);
    }

    /* buffer overflow */
    if ((pClient->m_recvSize + recvSize) >= MAX_SOCK_BUFF)
        return (0);

    pClient->m_lastRecvTime = getTime ();
    (void) memcpy (&pClient->m_recvBuff[pClient->m_recvSize], recvBuff, \
                    recvSize);
    pClient->m_recvSize += recvSize;

    return (1);
}
