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

typedef enum SceneType
{
    ST_SCENE1 = 1,
    ST_SCENE2 = 2,
    ST_SCENE3 = 3,
    ST_SCENE4 = 4,
} SceneType;

typedef enum SceneState
{
    SS_START = 1,
    SS_PAUSE = 2,
    SS_END   = 3,
} SceneState;

class CUserList
{
	typedef map<int, CClient*> CLIENTMAP;

public:
	 CUserList(int id, string class_name, string white_board);
	~CUserList ();

    friend class CHandleMessage;

    int  get_userlist_id();
    void add_client(int fd, CClient* pclient);
    void del_client(int fd);
    string get_userlist_name();

    CClient* get_client_by_fd (int fd);

    void add_course (CCourse *);
    void clear_all_course ();

    int  get_teacher_fd ();
    int  get_white_fd ();

    CUserList* get_userlist_by_fd (int fd);

    int reset();
    void teacher_disconnect();

    SceneType  get_current_st (void);
    SceneState get_current_ss (void);
    void set_current_st (SceneType);
    void set_current_ss (SceneState);

    void update_all_client_status (int fd, int flag); // offline = 0, leaveearly = 1

private:
    int m_isUsed;
    int m_userlist_id;
    string m_userlist_name;
    string m_class_name;
    CLIENTMAP m_client_map;

    SceneType   m_current_st;
    SceneState  m_current_ss;

    unsigned int m_node_id;
    int  m_is_show;
    int  m_current_scene;

private:
    MutexLock m_lock;
};

#endif //_C_USERLIST_H
