/*
 * userlist.cpp
 */

#include "userlist.h"
#include "client.h"

CUserList::CUserList()
{
}

CUserList::~CUserList()
{
}

void CUserList::add_client (int fd)
{
    CClient* pclient = NULL;

    CLIENTMAP::iterator iter = m_client_map.find (fd);

    if (iter != m_client_map.end ()) {
        printf ("fd [%d] is exist in the clientlist!", fd);
        delete (iter->second);
        m_client_map.erase (fd);
    }

    // create a new object, and set values.
    pclient = new CClient ();
    pclient->setSocket (fd);

    m_client_map.insert (pair<int, CClient*> (fd, pclient));
    printf ("socket fd[%d] by used, in the clientlist.\n", fd);
}

void CUserList::add_client (int fd, CClient* pclient)
{
#if 0
    CLIENTMAP::iterator iter = m_client_map.find(fd);

    if (iter != m_client_map.end()) {
        printf("fd [%d] is exist in the clientlist!", fd);
        delete iter->second;
        m_client_map.erase(fd);
    }

    m_client_map.insert(pair<int, CClient*>(fd, pclient));
    printf ("client=%p, used socket_fd=%d, into userlist (id=%d)\n", \
            pclient, fd, m_userlist_id);
#endif
}

void CUserList::del_client_by_fd (int fd)
{
}

void CUserList::del_client(int fd) {
#if 0
    CLIENTMAP::iterator it = m_client_map.find(fd);
    if ( m_client_map.end() != it) {
        printf("userlist [%d] client disconnected fd [%d] id [%i], name [%s]\n",
                m_userlist_id,
                it->first,
                it->second->getId(),
                it->second->getName().c_str());

        Buf* p = SINGLE->bufpool.malloc();
        MSG_HEAD* p_head = (MSG_HEAD*)p->ptr();
        p_head->cLen = sizeof(MSG_HEAD) + sizeof(TSendStudentStatusReq);
        p_head->cType = ST_SendStudentStatus;

        TSendStudentStatusReq body;
        body.client_id = it->second->getId();
        body.status = eCS_OFFLINE;//0xFFFFFFFF;
        memcpy(p_head->cData(), &body, sizeof(body));

        p->setsize(p_head->cLen);
        p->setfd(m_teacher_fd);
        SINGLE->sendqueue.enqueue(p);

        delete it->second;
        m_client_map.erase(it);
        CLIENTMAP::iterator itt;
        //向每个学生发送该学生断开消息
        for( itt = m_client_map.begin(); itt != m_client_map.end(); ++itt) {
            Buf* pp = SINGLE->bufpool.malloc();
            MSG_HEAD* pp_head = (MSG_HEAD*)pp->ptr();
            pp_head->cLen = sizeof(MSG_HEAD) + sizeof(TSendStudentStatusReq);
            pp_head->cType = ST_SendStudentStatus;
            memcpy(pp_head->cData(), &body, sizeof(body));
            pp->setsize(pp_head->cLen);
            pp->setfd(itt->first);
            SINGLE->sendqueue.enqueue(pp);
        }
    }
#endif
}
#if 0
void CUserList::del_client(int fd) {
    if (fd == m_teacher_fd) {
        printf("userlist [%d] teacher disconnected!\n", m_userlist_id);
        if (USERLISTMANAGER->get_userlist_by_fd (fd)->m_isUsed == 1)
            USERLISTMANAGER->get_userlist_by_fd (fd)->reset ();
        teacher_disconnect();
        m_teacher_fd = 0;
        return;
    }

    if (fd == m_white_fd) {
        printf("userlist [%d] whiteboard disconnected!\n", m_userlist_id);
        m_white_fd = 0;
        return;
    }
    //del_client(fd);

    // 改为向所有的学生端发送数据 (学生掉线处理也在其中)
    update_all_client_status (fd, 0);
}
#endif
CClient* CUserList::get_client_by_fd (int fd)
{
#if 1
    CLIENTMAP::iterator it = m_client_map.find(fd);
    if (it != m_client_map.end()) {
        return it->second;
    }
#endif
    return (NULL);
}

#if 0
CUserList* CUserList::get_userlist_by_fd (int fd)
{
#if 0
    CLIENTMAP::iterator itt;
    for (itt = m_client_map.begin(); itt != m_client_map.end(); ++itt) {
        printf("[client_fd=%d][client=%p]\n", itt->first, itt->second);
    }

    CLIENTMAP::iterator it = m_client_map.find(fd);
    if (it != m_client_map.end()) {
        return this;//it->second;
    }
    else if (fd == this->m_teacher_fd)
        return this;
    else if (fd == this->m_white_fd)
        return this;
    else
        return NULL;
#endif
    return (NULL);
}
#endif

int CUserList::reset ()
{
#if 0
    CLIENTMAP::iterator it;
    for (it = m_client_map.begin(); it != m_client_map.end();) {
#if 0
        delete it->second;
        m_client_map.erase(it++);
#else
        it->second->setSocket (0);
        it++;
#endif
    }


    //m_teacher_fd = 0;
    m_isUsed = 0;
    //m_teacher_name.clear();
    //m_white_fd = 0; // 老师退出电子教室时, 调用reset, 所有白板不用清理
    return 0;
#endif

    return (0);
}
