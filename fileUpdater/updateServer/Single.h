
/**
 * @ingroup framework
 */

#ifndef _GLOBAL_DATA_H_
#define _GLOBAL_DATA_H_

#include <stdio.h>
#include "AtomicT.h"
#include "QueueT.h"
#include "PoolT.h"
#include "Buf.h"

#define     MAX_BUFF_SIZE   8192
/**
 * @brief 全局单例
 */
class Single 
{
    public:
        ~Single();
        static class Single* instance();
        /**接收队列*/
        QueueT<Buf*> recvqueue;
        /**发送队列*/
        QueueT<Buf*> sendqueue;
        /**buf池*/
        PoolT<Buf> bufpool;

    private:
        Single();
        static class Single* p_;
};

#define SINGLE Single::instance()

///@}
#endif
