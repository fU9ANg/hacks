
#include "utils.h"

ssize_t send_with_select (int fd, void *buf, ssize_t left, struct timeval *time)
{
    if (buf == NULL || time == NULL) {
        return (-1);
    }

    ssize_t sended = 0;
    fd_set  set;

    while (left != 0) {
        FD_ZERO (&set);
        FD_SET  (fd, &set);
        int i = select (fd+1, NULL, &set, NULL, time);

        if (i <= 0) {
            break;  // select error
        }
        else {
            ssize_t len = send (fd, (void*) ((char*) buf + sended), left, 0);

            if (len == 0) {
                break;
            }
            else if (len == -1) {
                return (-1);
            }

            left   -= len;
            sended += len;
        }
    }

    return (sended);
}

ssize_t recv_with_select (int fd, void* buf, ssize_t left, struct timeval *time)
{
    if (buf == NULL || time == NULL) {
        return (-1);
    }

    ssize_t recved = 0;
    fd_set  set;

    while (left != 0) {
        FD_ZERO (&set);
        FD_SET  (fd, &set);
        int i = select (fd+1, &set, NULL, NULL, time);

        if (i <= 0) {
            break;
        }
        else {
            ssize_t len = recv (fd, (void*) ((char*) buf + recved), left, 0);
            if (len == 0) {
                break;
            }
            else if (len == -1) {
                return (-1);
            }

            left   -= len;
            recved += len;
        }
    }

    return (recved);
}

ssize_t send_with_check_errno (int fd, void *buf, ssize_t left)
{
    if (buf == NULL) {
        return (-1);
    }

    int sended = 0;
    while (left != 0) {
        int len = send (fd, (void*)((char*) buf + sended), left, 0);

        if (EAGAIN == errno) {
            usleep (100);
            continue;
        }

        if (EINTR == errno) {
            usleep (100);
            continue;
        }

        if (len == 0) {
            break;
        }

        if (len == -1) {
            return (-1);
        }

        left   -= len;
        sended += len;
    }

    return (sended);
}

ssize_t recv_with_check_errno (int fd, void *buf, ssize_t left)
{
    if (buf == NULL) {
        return (-1);
    }

    int recved = 0;
    while (left != 0) {
        int len = recv (fd, (void*)((char*) buf + recved), left, 0);

        if (EAGAIN == errno) {
            usleep (100);
            continue;
        }

        if (EINTR == errno) {
            usleep (100);
            continue;
        }

        if (len == 0) {
            break;
        }

        if (len == -1) {
            return (-1);
        }

        left   -= len;
        recved += len;
    }

    return (recved);
}
