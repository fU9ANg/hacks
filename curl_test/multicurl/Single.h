#ifndef __SINGLE_H__
#define __SINGLE_H__

#include <stdio.h>
#include <pthread.h>
#include "AtomicT.h"
#include "QueueT.h"
#include "PoolT.h"
#include "Buf.h"
//#include "task_curl.h"
#include "Uncopyable.h" // for class Uncopyable
#include "MapT.hpp"

class cCurlTask;
class Single : public Uncopyable
{
public :
	~Single();
	static class Single* instance();

	QueueT<Buf*> recvqueue;
	QueueT<Buf*> sendqueue;
	PoolT<Buf> bufpool;
    MapT<pthread_t, cCurlTask*> taskmap;


private :
	Single();

private:

	static class Single* p_;
};

#define SINGLE Single::instance()

#endif // __SINGLE_H__
