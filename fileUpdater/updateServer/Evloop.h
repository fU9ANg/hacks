
/**
 * @addtogroup framework
 * @{
 */

#ifndef EVLOOP_H_
#define EVLOOP_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <list>
#include <time.h>
#include <netinet/tcp.h>
#include <ev.h>

#include "Mutex.h"
#include "task.h"
#include "Single.h"
#include "Buf.h"
#include "Sock.h"
#include "AtomicT.h"

#define MAXFD       10240
#define TIMEOUT     10

typedef struct ev_io_info
{
    struct ev_io* io;
    ev_tstamp lasttime;
}   ev_in_info;

/**
 * @class Evloop
 * @brief event loop
 */
class Evloop: public task
{
    public:
        Evloop (string ip, int port);
        ~Evloop ();
        virtual int work ();
        /**
         * @brief callback function for accept,when new client connected;
         */
        static void accept_cb (struct ev_loop *loop, ev_io *w, int revents);
        /**
         * @brief callback function when received some data from client;
         */

        /**
         * @brief callback function when timeout
         */
        static void recv_cb (struct ev_loop *loop, ev_io *w, int revents);
        static void time_cb (struct ev_loop *loop, struct ev_timer *timer, int revents);
        /**
         * @brief set the fd as nonblock
         */
        static void setnonblock (int fd);
        static void setreuseaddr (int fd);
        static void setnodelay  (int fd);
        /**
         * @brief disconnect the client
         * @param[in] fd    the client to disconnect
         */
        static void closefd (int fd);

        /** event loop struct*/
        static struct ev_loop* loop;

        //用来记录每个fd的信息，ev_io*和上次收到数据的时间
        static struct ev_io_info ioarray[MAXFD];

        int getClientCount ();

    private:
        static AtomicT<int> clientcount;
        int    recvbuf (int fd);
        int    startlisten ();
        int    m_listenfd;
        int    m_port;
        string m_ip;
};

#endif
/**
 * @}
 */
