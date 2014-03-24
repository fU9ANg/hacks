#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <stdio.h>

#include "Uncopyable.h"

template <typename T>
class Singleton : public Uncopyable {
public :
	static T* instance(void) {
		if (NULL == p_) {
			p_ = new T();
		}
		++cnt;
		return p_;
	}
private :
	static T* p_;
	static int cnt;
	Singleton(void) {}
	~Singleton(void) {
		--cnt;
		if (0 == cnt) {
			delete p_;
			p_ = NULL;
		}
	}
};

template <typename T>
T* Singleton::p_ = NULL;
int Singleton::cnt = 0;

#endif//_SINGLETON_H
