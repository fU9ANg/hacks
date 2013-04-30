
/*
 * Written 2013 by fU9ANg
 * bb.newlife@gmail.com
 */

#include "define.h"
#include "packet.h"
#include "list.h"
#include "socket.h"
#include "utils.h"
#include "handler.h"

/* global variables */
int             g_ProcessLife = TRUE;
SOCKET          g_Socket      = INVALID_SOCKET;
struct sPacket* g_ClientList  = NULL;
int             g_TotalClient = 0;

void processLoop ();

void DestroySignal (int sigNum)
{
    g_ProcessLife = FALSE;
}

/*
====================
 initialize signal on the un*x
====================
*/
void initSignal (void)
{
    struct sigaction act;
    act.sa_handler = SIG_IGN;
    act.sa_flags  &= ~SA_RESETHAND;
    sigaction (SIGPIPE, &act, NULL);

    signal (SIGINT , DestroySignal);
    signal (SIGKILL, DestroySignal);
    signal (SIGQUIT, DestroySignal);
    signal (SIGTERM, DestroySignal);

}

int main ()
{
    initSignal  ();
    processLoop ();
    return (TRUE);
}

/*
====================
 initialize server data
====================
*/
void initServerData ()
{
    // TODO:
}

/*
====================
 destroy server data
====================
*/
void destroyServerData ()
{
    // TODO:
}

/*
====================
 Let's rock
====================
*/
void processLoop ()
{
    g_Socket = initServerSock (SERVER_PORT, MAX_LISTEN);
    if (g_Socket == INVALID_SOCKET)
        return;

    initServerData ();

    fd_set read_set;
    fd_set write_set;
    fd_set exce_set;

    struct timeval tv;
    SOCKET nfds;

    tv.tv_sec = 0;
    tv.tv_usec = 0;
    struct sPacket* client;
    struct sPacket* next_client;

    while (g_ProcessLife)
    {
        FD_ZERO (&read_set);
        FD_ZERO (&write_set);
        FD_ZERO (&exce_set);

        FD_SET (g_Socket, &read_set);
        nfds = g_Socket;

        LIST_WHILE (g_ClientList, client, next_client, m_next);

        if (client->m_sock > nfds)
            nfds = client->m_sock;

        FD_SET (client->m_sock, &read_set);
        FD_SET (client->m_sock, &write_set);
        FD_SET (client->m_sock, &exce_set);

        LIST_WHILEEND (g_ClientList, client, next_client);

        if (select (nfds + 1, &read_set, &write_set, &exce_set, &tv) < -1)
        {
            outLog ((char*)"select Error\r\n");
            continue;
        }

        if (FD_ISSET (g_Socket, &read_set))
            acceptNewClient (g_Socket);

        LIST_WHILE (g_ClientList, client, next_client, m_next);

        if (FD_ISSET (client->m_sock, &exce_set))
        {
            disconnectClient (client);
            LIST_SKIP (client, next_client);
        }

        if (client->m_lastRecvTime + 60000 <= getTime())
        {
            disconnectClient (client);
            LIST_SKIP (client, next_client);
        }

        if (FD_ISSET (client->m_sock, &read_set))
        {
            if (!recvFromClient (client))
            {
                disconnectClient (client);
                LIST_SKIP (client, next_client);
            }
        }

        if (client->m_recvSize)
        {
            if (!readRecvBuff (client))
            {
                disconnectClient (client);
                LIST_SKIP (client, next_client);
            }
        }
        LIST_WHILEEND (g_ClientList, client, next_client);

        LIST_WHILE (g_ClientList, client, next_client, m_next);
        if (client->m_sendSize && FD_ISSET (client->m_sock, &write_set))
        {
            if (flushSendBuff (client) < 0)
            {
                disconnectClient (client);
                LIST_SKIP (client, next_client);
            }
        }
        LIST_WHILEEND (g_ClientList, client, next_client);
    }

    destroyServerData ();
}
