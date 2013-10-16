/*
 * userlist.h
 */

#ifndef _C_USERLIST_H
#define _C_USERLIST_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <iostream>

#include "client.h"
#include "database.h"
#include "SQL.h"

#include "HandleMessage.h"

// number of client Per group
#define NUMS_STU_OF_GROUP   5

class CUserList
{
	typedef map<int, CClient*> CLIENTMAP;

public:
	 CUserList();
	~CUserList ();

    friend class CHandleMessage;

    void add_client (int fd);
    void add_client (int fd, CClient* pclient);
    void del_client_by_fd (int fd);
    void del_client (int fd);
    CClient* get_client_by_fd (int fd);
    int reset ();
    
private:
    CLIENTMAP m_client_map;
    MutexLock m_lock;
};

#endif //_C_USERLIST_H
