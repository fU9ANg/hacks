
#ifndef __UTILS_H
#define __UTILS_H

#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

extern ssize_t send_with_io_multiplexing (int fd, void *buf, ssize_t left, struct timeval *time);
extern ssize_t recv_with_io_multiplexing (int fd, void* buf, ssize_t left, struct timeval *time);
extern ssize_t send_with_polling (int fd, void *buf, ssize_t left);
extern ssize_t recv_with_polling (int fd, void *buf, ssize_t left);

#ifdef __cplusplus
}
#endif

#endif  //__UTILS_H
