
/**
 * @author  liu
 * @version  1.0
 * @addtogroup framework
 * @{
 */

#ifndef _ECSERVER_POOLT_H_
#define _ECSERVER_POOLT_H_

#include <queue>
#include <iostream>
#include <time.h>
#include <pthread.h>

#include "Mutex.h"

#define MAX_POOL_BUF    20000
using namespace std;

/**
 * @class   PoolT
 * @brief   memory pool
 * @  简易内存池
 */
template<typename TYPE>
class PoolT
{
public:

    /**
     * @brief   constructor
     * @param[in] n 初始化对象的个数，即池子大小
     */
    PoolT (int n = MAX_POOL_BUF)
    {
        this->m_size = n;
        for  (int i = 0; i < this->m_size; i++)
        {
            TYPE* p = new TYPE;
            this->m_queue.push (p);
        }
    }

    /**
     * @brief   destructor
     */
    ~PoolT ()
    {
        MutexLockGuard guard (m_lock);
        while  (!m_queue.empty ())
        {
            TYPE* p = this->m_queue.front ();
            this->m_queue.pop ();
            delete p;
        }
    }

    /**
     * @brief 分配内存
     * @retval 分配好的内存对象指针
     */
    TYPE* malloc ()
    {
        MutexLockGuard guard (m_lock);
        if  (m_queue.empty ())
        {
            return NULL;
        }
        TYPE* p = m_queue.front ();
        m_queue.pop ();
        return p;
    }

    /**
     * @brief 释放内存
     */
    int free (TYPE* i)
    {
        MutexLockGuard guard (m_lock);
        m_queue.push (i);
        return 0;
    }

    /**
     * @retval  池子大小
     */
    int size ()
    {
        return m_size;
    }

    /**
     * @retval  池子大小
     */
    int used ()
    {
      MutexLockGuard guard (m_lock);
      return m_size - m_queue.size ();
    }

private:
    queue<TYPE*> m_queue;
    MutexLock m_lock;
    int m_size;
};

/**
 * @}
 */
#endif
