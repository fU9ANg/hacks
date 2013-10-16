#include "ThreadPool.h"

ThreadPool::ThreadPool(int n):
    free_(0) {
    count = n;
}
ThreadPool::~ThreadPool() {
}

int ThreadPool::start() {
    state_ = 1;
    for(int i = 0; i < count; ++i){
        pthread_t tid = 0;
        pthread_create(&tid, 0, ThreadPool::thread, this);
        MutexLockGuard gard(ListLock_);
        this->threads_.push_back(tid);
    }
    return 0;
}

int ThreadPool::stop() {
    state_ = 0;
    while(0 != this->getcount()){
        usleep(100);
    }
    return 0;
}

int ThreadPool::push_task(task* p) {
    return this->TaskQueue_.enqueue(p);
}

int ThreadPool::getcount() {
    MutexLockGuard gard(ListLock_);
    return this->threads_.size();
}

void* ThreadPool::thread(void* p) {
    signal(SIGRTMIN, sighandle);
    ThreadPool* pp = static_cast<ThreadPool*>(p);
    task* t = NULL;
    while(0 != pp->state_.value()){
        if(0 == pp->TaskQueue_.dequeue(t,3) && NULL != t){
            pp->free_ ++;
            t->work();
            pp->free_ --;
            if(t->autorelease)
            {
                delete t;
                t = NULL;
            }
        }else{
            t = NULL;
        }
    }
    MutexLockGuard gard(pp->ListLock_);
    pp->threads_.remove(pthread_self());
    return NULL;
}

int ThreadPool::kill() {
    MutexLockGuard gard(this->ListLock_);
    while(!threads_.empty()) {
        cout << ".l........." << endl;
        pthread_kill(threads_.front(), SIGRTMIN);
        threads_.pop_front();
    }
    return 0;
}

void ThreadPool::sighandle(int signo) {
    printf("[%ld]exit\n", pthread_self());
    pthread_exit(NULL);
    return;
}
