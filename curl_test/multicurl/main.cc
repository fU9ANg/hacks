
#include <stdio.h>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include "AtomicT.h"
#include "QueueT.h"
#include "Mutex.h"
#include "PoolT.h"
#include "Buf.h"
#include <pthread.h>
#include <curl/curl.h>
#include "Single.h"

#include "net_curl.h"
#include "task_curl.h"

#if 0
TaskInfo taskInfo[3] = {
    {"xxxxx", "http://xxxxx", 0, 0, NULL, 0},
    {"xxxxx", "http://xxxxx", 0, 0, NULL, 0},
    {"xxxxx", "http://xxxxx", 0, 0, NULL, 0},
};
#endif

int main (int argc, char** argv)
{
    cNetCurl* p = new cNetCurl();
    p->init (3);

    p->SetUrlToQueue ("sj02.tar"  , "http://192.168.0.79:8080/books/upload/files/BooksID6/sj02.tar"  );
    p->SetUrlToQueue ("sj03.tar"  , "http://192.168.0.79:8080/books/upload/files/BooksID6/sj03.tar"  );
    p->SetUrlToQueue ("sj01.tar"  , "http://192.168.0.79:8080/books/upload/files/BooksID6/sj01.tar"  );
    p->SetUrlToQueue ("glsj02.tar", "http://192.168.0.79:8080/books/upload/files/BooksID7/glsj02.tar");
    while (true) {
        printf ("------------------\nmain pthread.\n");
        sleep (2);
    }
    delete p;

    return (0);
}
