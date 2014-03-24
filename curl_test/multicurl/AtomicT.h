#ifndef __ATOMICT_H__
#define __ATOMICT_H__

#include "Mutex.h"
#include <iostream> // for std::swap

template <typename TYPE>
class AtomicT {
public :
	AtomicT(void) : m_value() {}
	AtomicT(const TYPE& rhs) : m_value(rhs) {}
	~AtomicT(void) {}

	TYPE value(void) {
		MutexLockGuard guard (m_lock);
		return this->m_value;
	}

	TYPE operator+= (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value += rhs;
	}

	TYPE operator-= (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value -= rhs;
	}

	TYPE operator++ (void) {
		MutexLockGuard guard (m_lock);
		return ++this->m_value;
	}

	TYPE operator++ (int) {
		MutexLockGuard guard (m_lock);
		return this->m_value++;
	}

	TYPE operator-- (void) {
		MutexLockGuard guard (m_lock);
		return --this->m_value;
	}

	TYPE operator-- (int) {
		MutexLockGuard guard (m_lock);
		return this->m_value--;
	}

	const AtomicT<TYPE>& operator= (const TYPE& rhs) {
		AtomicT<TYPE> tmp (rhs);
		MutexLockGuard guard (m_lock);
		std::swap (this->m_value, tmp.m_value);
		return *this;
	}

	bool operator== (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value == rhs;
	}

	bool operator!= (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value != rhs;
	}

	bool operator> (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value > rhs;
	}

	bool operator>= (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value >= rhs;
	}

	bool operator< (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value < rhs;
	}

	bool operator<= (const TYPE& rhs) {
		MutexLockGuard guard (m_lock);
		return this->m_value <= rhs;
	}

private :
	TYPE m_value;
	MutexLock m_lock;
};

#endif  // __ATOMICT_H__
