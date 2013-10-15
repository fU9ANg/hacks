
/**
 * @author  liu
 * @version  1.0
 * @{
 */

#ifndef _QUEUET_H_
#define _QUEUET_H_

#include <queue>
#include <iostream>
#include <time.h>
#include <pthread.h>

#include "Mutex.h"

using namespace std;

/**
 * @class   QueueT
 * @brief   simple blocking queue
 */
template<typename TYPE>
class QueueT
{
public:
    /**
     * @brief   constructor
     */
    QueueT () {
        pthread_mutex_init (&m_mutex, NULL);
        pthread_cond_init (&m_con, NULL);
    }
    /**
     * @brief   destructor
     */
    ~QueueT () {
        pthread_mutex_destroy (&m_mutex);
        pthread_cond_destroy (&m_con);
    }

    /**
     *@param[in]  timeout     timeout
     *@param[out] out         out element 
     *@retval     0           success
     *@retval     -1          timeout
     */
    int dequeue (TYPE& out, unsigned int timeout) {
        struct timespec t;
        t.tv_sec = time (NULL) + timeout;
        t.tv_nsec = 0;
        pthread_mutex_lock (&m_mutex);
        while  (m_queue.empty ()) {
            if  (0 != pthread_cond_timedwait (&m_con, &m_mutex, &t)) {
                //timeout
                pthread_mutex_unlock (&m_mutex);
                return -1;
            } 
        }
        out = m_queue.front ();
        m_queue.pop ();
        pthread_mutex_unlock (&m_mutex);
        return 0;
    }

    /**
     *@param[in]  t         in element
     */
    int enqueue (TYPE t) {
        pthread_mutex_lock (&m_mutex);
        if  (m_queue.empty ()) {
            m_queue.push (t);
            pthread_mutex_unlock (&m_mutex);
            pthread_cond_signal (&m_con);
        } else {
            m_queue.push (t);
            pthread_mutex_unlock (&m_mutex);
        }
        return 0;
    }

    /**
     * @brief   get size of queue
     * @retval  size
     */
    size_t size () {
        pthread_mutex_lock (&m_mutex);
        size_t size = m_queue.size ();
        pthread_mutex_unlock (&m_mutex);
        return size;
    }

private:
    /**MutexLock*/
    pthread_mutex_t m_mutex;
    /**ConMutex*/
    pthread_cond_t m_con;
    /**queue*/
    queue<TYPE> m_queue;
};

/**
 * @}
 */
#endif
