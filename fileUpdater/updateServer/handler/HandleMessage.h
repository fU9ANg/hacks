
/*
 * HandleMessage.h
 */

#ifndef _HANDLE_MESSAGE_H
#define _HANDLE_MESSAGE_H

#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "protocol.h"
#include "Single.h"
#include "Buf.h"
#include "SQL.h"

using namespace std;

#define _EXECUTE_

typedef void (*handlefunc)(Buf*);
typedef map<int, handlefunc> HANDLEMAP;

class CHandleMessage
{
public:

    #define MSGNAME(name, handle) static void handle (Buf* p)
    #include "MSGHANDLE"
    #undef MSGNAME

public:
    static handlefunc getHandler (int iCommandType)
    {
        HANDLEMAP::iterator it = CHandleMessage::m_HandleMap.find(iCommandType);
        if (it != CHandleMessage::m_HandleMap.end())
            return it->second;

        return NULL;
    }

    static void initHandlers (void)
    {
        #define MSGNAME(name, handle) \
            CHandleMessage::setHandler (name, &CHandleMessage::handle)
        #include "MSGHANDLE"
        #undef MSGNAME
    }

    static void setHandler (int iCommandType, handlefunc hHandler)
    {
        if (hHandler != NULL)
            m_HandleMap.insert (std::pair<int, handlefunc>(iCommandType, hHandler));
    }

private:
    static bool postMessage (Buf* p, enum CommandType iCommandType, void* data, unsigned int iLen);

    static bool postTeacherToWhite (Buf* p, enum CommandType);
    static bool postStudentToWhite (Buf* p, enum CommandType);
    static bool postWhiteToTeacher (Buf* p, enum CommandType);

    static bool postTeacherToAllStudent (Buf* p, enum CommandType);
    static bool postTeacherToStudent    (Buf* p, enum CommandType, int iStuId);

    static bool postDBRecordCount (Buf* p, int iCase);
    static bool postDBRecord      (Buf* p, int iCase);

private:
    static HANDLEMAP m_HandleMap;

public:
    static int    test_white_fd;

};


#endif //_HANDLE_MESSAGE_H
