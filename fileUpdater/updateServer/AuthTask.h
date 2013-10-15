
/**
 * @addtogroup framework
 * @{
 */

#ifndef AUTHTASK_H_
#define AUTHTASK_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

#include "task.h"
#include "Sock.h"
#include "Single.h"
#include "Buf.h"

#define INTERVAL_TIME   3600

/**
 * @brief 检测授权线程任务
 */
class AuthTask: public task
{
    public:
        AuthTask();
        ~AuthTask();
        virtual int work();

    private:
        time_t m_oldtime;
};

#endif

///@}
