
/**
 * @file AtomicT.h
 */

#ifndef _ECSERVER_ATOMICT_H_
#define _ECSERVER_ATOMICT_H_

#include <pthread.h>
#include <algorithm>
#include "Mutex.h"

template <typename TYPE>
class AtomicT
{
    public:
        AtomicT()
        {
            m_value = 0;
        }

        AtomicT(TYPE a)
        {
            m_value = a;
        }

        ~AtomicT()
        {
        }

        TYPE value()
        {
            MutexLockGuard guard (m_lock);
            return this->m_value;
        }

        TYPE operator+= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value += a;
        }

        TYPE operator-= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value -= a;
        }

        /**
         * @brief pre-increment
         */
        TYPE operator++ (void)
        {
            MutexLockGuard guard (m_lock);
            return ++this->m_value;
        }

        /**
         * @brief post-increment
         */
        TYPE operator++ (int)   // parameter must is int type
        {
            MutexLockGuard guard (m_lock);
            return this->m_value++;
        }

        TYPE operator-- (void)
        {
            MutexLockGuard guard (m_lock);
            return --this->m_value;
        }

        TYPE operator-- (int)  // parameter must is int type
        {
            MutexLockGuard guard (m_lock);
            return this->m_value--;
        }

        AtomicT<TYPE>& operator= (TYPE a)
        {
            AtomicT<TYPE> tmp (a);
            MutexLockGuard guard (m_lock);
            std::swap (this->m_value, tmp.m_value);
            return *this;
        }

        bool operator== (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value == a;
        }

        bool operator!= (TYPE a) 
        {
            MutexLockGuard guard (m_lock);
            return this->m_value != a;
        }

        bool operator> (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value > a;
        }

        bool operator>= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value >= a;
        }

        bool operator< (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value < a;
        }

        bool operator<= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value <= a;
        }

    private:
        TYPE m_value;
        MutexLock m_lock;
};

#endif  // _ECSERVER_ATOMICT_H_
