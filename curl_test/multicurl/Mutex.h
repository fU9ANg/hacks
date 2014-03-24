#ifndef __LOCK_H__
#define __LOCK_H__

#include <pthread.h>

#include "Uncopyable.h" // for class Uncopyable

class MutexLock : public Uncopyable {
public :
	MutexLock(void) {
		pthread_mutex_init (&mutex_, NULL);
	}

	~MutexLock(void) {
		pthread_mutex_destroy (&mutex_);
	}

	void lock(void) { 
		pthread_mutex_lock (&mutex_);
	}

	void unlock(void) { 
		pthread_mutex_unlock (&mutex_);
	}

	pthread_mutex_t* getPthreadMutex(void)
	{ 
		return &mutex_;
	}

private :
	pthread_mutex_t mutex_;
};

class MutexLockGuard : public Uncopyable {
public :
	explicit MutexLockGuard (MutexLock& mutex) : mutex_ (mutex) { 
		mutex_.lock ();
	}

	~MutexLockGuard (void) { 
		mutex_.unlock ();
	}

private :
	MutexLock& mutex_;
};

class Condition : public Uncopyable
{
public:
	Condition (MutexLock& m):mutex_ (m) {
		pthread_cond_init (&pcond_, NULL);
	}

	int wait (void) {
		pthread_cond_wait (&pcond_,mutex_.getPthreadMutex ());
		return 0;
	}

	int wait (time_t t) {
		struct timespec timeout;
		timeout.tv_sec = time (NULL) + t;
		timeout.tv_nsec = 0;
		return pthread_cond_timedwait (&pcond_,mutex_.getPthreadMutex (), &timeout);
	}

	void notify(void) {
		pthread_cond_signal (&pcond_);
	}

	void notifyall(void) {
		pthread_cond_broadcast (&pcond_);
	}

	~Condition(void) {
		pthread_cond_destroy (&pcond_);
	}
private:
	MutexLock& mutex_;
	pthread_cond_t pcond_;
};

#define MutexLockGuard(x) static_assert (false, "missing mutex guard variable name")

#endif // __LOCK_H__
