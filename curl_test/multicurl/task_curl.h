#ifndef __TASK_CURL_H_
#define __TASK_CURL_H_

#include <pthread.h>
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

using namespace std;

class cCurlTask
{
public:
    cCurlTask (string n, string u, pthread_t t, int p)
        : _filename (n), _url (u), _tid (t), _progress (p)
    {
        _fp = NULL;
        _progress = 0;
        _filesize = get_file_size (_filename.c_str());
    }

    ~cCurlTask ()
    {
        close_file ();
    }

    CURLcode init_curl ()
    {
        //MutexLockGuard guard (m_mutex);
        this->_handler = curl_easy_init ();
        if (this->_handler == NULL) {
            cout << "[cCurlTask-Debug]: error - init curl easy _handler failed, tid=" 
                 << this->_tid
                 << ", pthread_self()="
                 << pthread_self () << endl;
            return (CURLE_FAILED_INIT);
        }
    }

    bool open_file ()
    {
        //MutexLockGuard guard (m_mutex);
        cout << "open filename = " << _filename.c_str() << endl;
        _fp = fopen (_filename.c_str(), "ab+");
        if (_fp == NULL) {
            cout << "[cCurlTask-Debug]: error - open file and get fd failed, tid=" 
                 << this->_tid
                 << ", pthread_self()="
                 << pthread_self () << endl;

            return (false);
        }

        return (true);
    }

    void close_file ()
    {
        if (_fp != NULL)
            fclose (_fp);
    }

    static size_t write_callback (void* buffer, size_t size, size_t num, void* server_data)
    {
        FILE* fp = (FILE*) server_data;
        size_t return_n = fwrite (buffer, size, num, fp);
        return (return_n);
    }

    int rename_file (const char* oldpath, const char* newpath)
    {
        if (oldpath == NULL || newpath == NULL)
            return (-1);
        return (rename (oldpath, newpath));
    }

    CURLcode setopt ()
    {
        long fsize = get_file_size (this->_filename.c_str());

        MutexLockGuard guard (m_mutex);

        curl_easy_setopt     (this->_handler, CURLOPT_URL, _url.c_str ());

        if (this->_filename.find (".tar") != string::npos) {
            curl_easy_setopt (this->_handler, CURLOPT_RESUME_FROM_LARGE, (curl_off_t) fsize);
            curl_easy_setopt (this->_handler, CURLOPT_NOPROGRESS, 0L);
            curl_easy_setopt (this->_handler, CURLOPT_PROGRESSFUNCTION, cCurlTask::progress_callback);
        }

        curl_easy_setopt     (this->_handler, CURLOPT_WRITEFUNCTION, &cCurlTask::write_callback);
        curl_easy_setopt     (this->_handler, CURLOPT_WRITEDATA,     _fp);

        return (CURLE_OK);
    }

    static int progress_callback (void* ptr, double total, double now, double uptotal, double upnow)
    {
        //printf ("[cCurlTask-Debug]: - progress_callback pthread_self()=%ld\n", pthread_self ());
        cCurlTask* task = SINGLE->taskmap.get_obj_by_key (pthread_self());
        
        if ((int) total == 0 && (int) now == 0) {
            task->progress(0);
        }
        else {
            int current_progress = 0;
            current_progress = (int) (100.0 * ((now + (task->filesize ())) / (total + (task->filesize ()))));
            
            if (current_progress > task->progress()) {
                task->progress (current_progress);
                printf ("tid=%ld, task.tid=%ld, progress=%d%%\n", pthread_self (), task->tid (), task->progress ());
            }
        }

        return (0);
    }

    CURLcode perform ()
    {
        CURLcode rc;

        rc = curl_easy_perform (this->_handler);

        if (rc != CURLE_OK) {
            cout << "[cCurlTask-Debug]: error - perform failed, tid=" 
                 << this->_tid
                 << ", pthread_self()="
                 << pthread_self () 
                 << ", CURLcode="
                 << rc
                 << endl;
        }

        return (rc);
    }

    long get_local_file_size (const char* localpath)
    {
        long   fsize = 0;
        struct stat statbuf;
        MutexLockGuard guard (m_mutex);

        if (stat (localpath, &statbuf) < 0) {
            fsize = 0;
        }
        else {
            fsize = statbuf.st_size;
        }
        return (fsize);
    }

    long get_file_size (const char* path)
    {
        long  fsize = 0;
        FILE* fp;
        MutexLockGuard guard (m_mutex);

        if ((fp = fopen (path, "r")) == NULL) {
            fsize = 0;
        }
        else {
            fseek (fp, 0L, SEEK_END);
            fsize = ftell (fp);
            fclose (fp);
        }

        return (fsize);
    }
    
    void handler (CURL* h) {
        this->_handler = h;
    }
    
    CURL* handler (void) {
        return (_handler);
    }
    
    string filename (void) {
        return (_filename);
    }
    
    void filename (string s) {
        _filename = s;
    }
    
    void url (string s) {
        _url = s;
    }
   
    void tid (pthread_t t) {
        _tid = t;
    }
    
    void progress (int p) {
        _progress = p;
    }
    
    void filesize (size_t fs) {
        _filesize = fs;
    }
    
    void fp (FILE* f) {
        _fp = f;
    }
    
    string url (void) {
        return (_url);
    }
    
    pthread_t tid (void) {
        return (_tid);
    }
    
    int progress (void) {
        return (_progress);
    }
    
    size_t filesize (void) {
        return (_filesize);
    }
    
    FILE* fp (void) {
        return (_fp);
    }
    
    
private:
    MutexLock   m_mutex;
    CURL*       _handler;
    string      _filename;
    string      _url;
    pthread_t   _tid;
    int         _progress;
    FILE*       _fp;
    size_t      _filesize;
};

#endif  // __TASK_CURL_H_
