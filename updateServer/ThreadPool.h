/**
 * @ingroup framework
 * @{
 */
#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_
#include <pthread.h>
#include <stdio.h>
#include <list>
#include <signal.h>
#include "QueueT.h"
#include "task.h"
#include "AtomicT.h"
#include "Mutex.h"

/**
 * @class ThreadPool
 * @brief 线程池
 */
class ThreadPool{
    public:
        ThreadPool(int n);
        ~ThreadPool();
        int start();
        int stop();
        int kill();
        int push_task(task* p);
        static void* thread(void* p);
        static void sighandle(int signo);
        int getcount();
        int getfree();
    private:
        list<pthread_t> threads_;
        QueueT<task*> TaskQueue_;
        AtomicT<int> state_;
        AtomicT<int> free_;
        int count;
        MutexLock ListLock_;
};
#endif
///@}
