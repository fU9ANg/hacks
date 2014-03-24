#ifndef __POOLT_H__
#define __POOLT_H__

#include <queue>
#include "Mutex.h"
#include "netdef.h"

template<typename TYPE>
class PoolT {
public :
	PoolT(int size = POOLT_MAX_SIZE) : m_size(size) {
		for (int i=0; i<m_size; ++i) {
			m_queue.push(new TYPE);
		}
	}

	~PoolT(void) {
		MutexLockGuard guard(m_lock);
		while (!m_queue.empty ()) {
			TYPE* p = m_queue.front();
			m_queue.pop();
			delete p;
		}
	}

	TYPE* malloc(void) {
		MutexLockGuard guard (m_lock);
		if (m_queue.empty()) {
			return NULL;
		}
		TYPE* p = m_queue.front ();
		m_queue.pop ();
		return p;
	}
	int free(TYPE* i) {
		MutexLockGuard guard (m_lock);
		m_queue.push (i);
		return 0;
	}

	int size(void) {
		return m_size;
	}

	int used(void) {
		MutexLockGuard guard (m_lock);
		return m_size - m_queue.size ();
	}

private :
	std::queue<TYPE*> m_queue;
	MutexLock m_lock;
	int m_size;
};

#endif // __POOLT_H__
