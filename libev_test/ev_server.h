
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <ev.h>
#include <errno.h>
#include <iostream>
#include <string>

#define OUT(result, exp, fmt, ...) do {         \
    if (exp) {                                  \
        fprintf (stderr, fmt, ##__VA_ARGS__);   \
        result;                                 \
    }                                           \
} while (0)

using namespace std;

typedef struct ev_io_struct
{
    struct ev_io    *io;
    ev_tstamp       lasttime;
}   EV_IO_STRUCT;

class EVServer
{
    public:
        EVServer (string ip, int port);
        ~EVServer ();

        // callback
        static void accept_callback (struct ev_loop *loop, ev_io *io, int revents);
        static void read_callback   (struct ev_loop *loop, ev_io *io, int revents);
        static void write_callback  (struct ev_loop *loop, ev_io *io, int revents);
        static void error_callback  (struct ev_loop *loop, ev_io *io, int revents);

        static void timer_callback  (struct ev_loop *loop, struct ev_timer *timer, int revents);

        static void close_client (int fd);

    public:
        static struct ev_loop* loop;
        static struct ev_io_struct ios[MAXFD];
};
