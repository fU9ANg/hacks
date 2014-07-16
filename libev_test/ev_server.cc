
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

#define OUT(result, exp, fmt, ...) do {         \
    if (exp) {                                  \
        fprintf (stderr, fmt, ##__VA_ARGS__);   \
        result;                                 \
    }                                           \
} while (0)

typedef struct ev_io_struct
{
    struct ev_io    *io;
    ev_tstamp       lasttime;
}   EV_IO_STRUCT;

class 
