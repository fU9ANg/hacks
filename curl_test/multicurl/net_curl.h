#ifndef _NETCURL_H_
#define _NETCURL_H_

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
#include <map>
#include <curl/curl.h>
#include "Single.h"
#include "task_curl.h"
#include "Uncopyable.h"
#include "MapT.hpp"

#define MAX_FILE_NAME   128
#define MAX_URL         128

using namespace std;

#if 0
typedef struct sTaskInfo {
    char        url[MAX_URL];
    char        filename[MAX_FILE_NAME];
    pthread_t   tid;
    int         progress;
    FILE*       fp;
    size_t      filesize;
} TaskInfo;
#endif
class cNetCurl : public Uncopyable
{
public:
    static void* thread_GetServerDataWithCurl (void* data)
    {
        Buf* pbuf = NULL;
        while (true) {
            pbuf = NULL;
            if (SINGLE->recvqueue.dequeue (pbuf, 1) != 0) {
                //printf ("try get a buffer and continue, tid=%ld\n", pthread_self ());
                sleep (1);
                continue;
            }

            if (pbuf == NULL) {
                cout << "[cNetCurl-Debug]: error - pbuf==NULL" 
                     << ", pthread_self()="
                     << pthread_self () << endl;
                continue;
            }

            printf ("[cNetCurl-Debug]: goto execute download task, tid=%ld\n", pthread_self());
#if 0
            TaskInfo* tinfo = NULL;
            printf ("url=%s, filename=%s\n", (char*)pbuf->ptr(), (char*)pbuf->fileptr());
            (void) memcpy (tinfo->filename, (char*)pbuf->fileptr(), sizeof (pbuf->fileptr()));
            (void) memcpy (tinfo->url     , (char*)pbuf->ptr()    , sizeof (pbuf->ptr()));
            tinfo->tid      = pthread_self ();
            tinfo->progress = 0;
            tinfo->filesize = 0;
            tinfo->fp       = NULL;
            cCurlTask* task = new cCurlTask (tinfo->filename, 
                                             tinfo->url,
                                             tinfo->tid,
                                             tinfo->progress);
#else
            cCurlTask* task = new cCurlTask ((char*)pbuf->fileptr(), 
                                             (char*)pbuf->ptr(),
                                             pthread_self (),
                                             0);
            SINGLE->taskmap.insert (pthread_self(), task);

            task->init_curl ();
            task->open_file ();
            task->setopt ();
            task->perform ();
            delete task;
#endif
            sleep (1);
            printf ("[cNetCurl-Debug]: free buffer, tid=%ld\n", pthread_self());
            pbuf->reset ();
            SINGLE->bufpool.free (pbuf);
        }
    }

    static bool SetUrlToQueue (const std::string& filename, const std::string& url)
    {
        printf ("[JSON-DATA]: SetUrlToQueue begin.\n");
        size_t len = 0;

        Buf* pbuf = SINGLE->bufpool.malloc();
        if (!pbuf)
        {
            return (false);
        }

        len = url.size();
        printf ("[JSON-DATA]: SetUrlToQueue filename=%s, url=%s.\n", filename.c_str(), url.c_str());
        (void) memcpy ((char*)pbuf->ptr(), url.c_str(), url.size());
        (void) memcpy ((char*)pbuf->fileptr(), filename.c_str(), filename.size());

        printf ("[JSON-DATA]: insert pbuf to recvqueue  QUEUESIZE=%ld  begin\n", SINGLE->recvqueue.size());
        SINGLE->recvqueue.enqueue (pbuf);
        printf ("[JSON-DATA]: insert pbuf to recvqueue  QUEUESIZE=%ld  after\n", SINGLE->recvqueue.size());

        return (true);
    }

    static Buf* GetQueueData (void)
    {
        Buf* pbuf = NULL;
        if (SINGLE->sendqueue.dequeue (pbuf, 0) != 0) {
            return NULL;
        }
        if (!pbuf)
        {
            return NULL;
        }
        return (pbuf);
    }

    void init (int pthread_n)
    {
        CURLcode rc;
        MutexLockGuard guard (m_mutex);

        rc = curl_global_init (CURL_GLOBAL_ALL);
        if (rc != CURLE_OK) {
            printf ("[JSON-DATA]: error - init libcurl failed.");
            return;
        }

        for (int i=0; i<pthread_n; i++) {
            printf ("pthread_create %d\n", i);
            pthread_t tid;
            pthread_create (&tid, NULL, &cNetCurl::thread_GetServerDataWithCurl, NULL);
            //taskInfo[i].url[0] = 0x00;
            
        }

        curl_global_cleanup ();
        sleep (2);
    }
private:
    MutexLock   m_mutex;
};


#endif  //_NETCURL_H_
