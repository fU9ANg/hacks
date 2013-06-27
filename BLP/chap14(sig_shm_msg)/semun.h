
#include <sys/sem.h>

#ifndef _SEMUN_H
#define _SEMUN_H

union semun {
    int val;    /* value of SETVL */
    struct semid_ds* buf; /* buffer for IPC_STAT, IPC_SET */
    unsigned short* array; /* array for GETALL, SETALL */
    struct seminfo* __buf; /* buffer for IPC_INFO */
};

#endif
