
/**
 * @addtogroup framework
 * @{
 */

#ifndef _MUTEX_LOCK_H_
#define _MUTEX_LOCK_H_

#include <pthread.h>

/**
 * @class MutexLock
 * @brief 互斥锁
 */
class MutexLock
{
    public:
        MutexLock ()
        {
            pthread_mutex_init (&mutex_, NULL);
        }

        ~MutexLock ()
        {
            pthread_mutex_destroy (&mutex_);
        }

        void lock ()
        { 
            pthread_mutex_lock (&mutex_);
        }

        void unlock ()
        { 
            pthread_mutex_unlock (&mutex_);
        }

        pthread_mutex_t* getPthreadMutex ()
        { 
            return &mutex_;
        }

    private:
        MutexLock (const MutexLock& t);
        const MutexLock& operator= (const MutexLock&);
        pthread_mutex_t mutex_;
};

/**
 * @class MutexLockGuard
 */
class MutexLockGuard
{
    public:
        explicit MutexLockGuard (MutexLock& mutex) : mutex_ (mutex) { 
            mutex_.lock ();
        }
        ~MutexLockGuard () { 
            mutex_.unlock ();
        }
    private:
        MutexLockGuard (const MutexLockGuard& t);
        const MutexLockGuard& operator= (const MutexLockGuard&);
        MutexLock& mutex_;
};

/**
 * @class Condition
 * @brief 条件变量
 */
class Condition
{
    public:
        Condition (MutexLock& m):mutex_ (m){
            pthread_cond_init (&pcond_, NULL);
        }

        int wait (){
            pthread_cond_wait (&pcond_,mutex_.getPthreadMutex ());
            return 0;
        }

        int wait (time_t t){
            struct timespec timeout;
            timeout.tv_sec = time (NULL) + t;
            timeout.tv_nsec = 0;
            return pthread_cond_timedwait (&pcond_,mutex_.getPthreadMutex (), &timeout);
        }

        void notify (){
            pthread_cond_signal (&pcond_);
        }

        void notifyall (){
            pthread_cond_broadcast (&pcond_);
        }

        ~Condition (){
            pthread_cond_destroy (&pcond_);
        }
    private:
        Condition (const Condition& t);
        MutexLock& mutex_;
        pthread_cond_t pcond_;
};

#define MutexLockGuard(x) static_assert (false, "missing mutex guard variable name")

#endif
///@}
