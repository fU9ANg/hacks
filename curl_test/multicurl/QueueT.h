#ifndef __QUEUET_H__
#define __QUEUET_H__

#include <queue>
#include "Mutex.h"

template<typename TYPE>
class QueueT {
public :
	QueueT(void) {
		pthread_mutex_init (&m_mutex, NULL);
		pthread_cond_init (&m_con, NULL);
	}

	~QueueT(void) {
		pthread_mutex_destroy (&m_mutex);
		pthread_cond_destroy (&m_con);
	}

	int dequeue(TYPE& out, unsigned int timeout) {
		struct timespec t;
		t.tv_sec = time (NULL) + timeout;
		t.tv_nsec = 0;
		pthread_mutex_lock (&m_mutex);
		while  (m_queue.empty ()) {
			if  (0 != pthread_cond_timedwait (&m_con, &m_mutex, &t)) { //timeout
				pthread_mutex_unlock (&m_mutex);
				return -1;
			} 
		}
		out = m_queue.front ();
		m_queue.pop ();
		pthread_mutex_unlock (&m_mutex);
		return 0;
	}

	bool dequeue(TYPE& out) {
		pthread_mutex_lock (&m_mutex);
		while  (m_queue.empty ()) {
			pthread_mutex_unlock (&m_mutex);
			return false;
		}
		out = m_queue.front ();
		m_queue.pop ();
		pthread_mutex_unlock (&m_mutex);
		return true;
	}

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

	size_t size(void) {
		pthread_mutex_lock (&m_mutex);
		size_t size = m_queue.size ();
		pthread_mutex_unlock (&m_mutex);
		return size;
	}

	/*
	   void clean(void)
	   {
	   pthread_mutex_lock (&m_mutex);
	   m_queue.();
	   pthread_mutex_unlock (&m_mutex);
	   }
	   */

private :
	pthread_mutex_t m_mutex;
	pthread_cond_t m_con;
	std::queue<TYPE> m_queue;
};

#endif // __QUEUET_H__
