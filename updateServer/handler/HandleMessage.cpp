
/*
 * HandleMessage.cpp
 */
#include "HandleMessage.h"

#include "protocol.h"
#include "Buf.h"
//#include "roommanager.h"
//#include "teacher.h"
#include "Single.h"

/////////////////////
HANDLEMAP CHandleMessage::m_HandleMap;
//CGroup CHandleMessage::test_group;
int CHandleMessage::test_white_fd = 0;

/*
=====================
 转发信息的通用接口
=====================
*/
bool CHandleMessage::postMessage (Buf* p, enum CommandType iCommandType, void* data, unsigned int iLen)
{
    //cout << "postMessage.........." << endl;
    if (p == NULL)
        return false;

    MSG_HEAD* head = (MSG_HEAD*)p->ptr();
    head->cLen = sizeof (MSG_HEAD);
    head->cType = iCommandType;

    if (data != NULL) {
        head->cLen = head->cLen + iLen;
        (void) memcpy ((char*)p->ptr() + sizeof (MSG_HEAD), (char*)data, iLen);
    }

    p->setsize (head->cLen);
    SINGLE->sendqueue.enqueue (p);

    return true;
}

/*
=====================
 转发教师端数据到白板端
=====================
*/
bool CHandleMessage::postTeacherToWhite (Buf* p, enum CommandType iCommandType)
{
#if 0
    if (p == NULL)
        return false;

#ifdef TEACHER_NOT_LOGIN
    CRoom* proom = ROOMMANAGER->get_room_by_name("A教室");

    if( NULL == proom) {
        SINGLE->bufpool.free(p);       
        return false;
    }  
    proom->set_teacher_fd(p->getfd());                                                                                                                                       
    proom->set_teacher_name("教师A");
    proom->set_class_name("一班");
    printf("Teacher login class room [%d] success!\n", proom->get_room_id());
#endif

    cout << "postTeacherToWhite............................ " << endl;
    CRoom* pc = ROOMMANAGER->get_room_by_fd (p->getfd());

    //if (pc != NULL)
    if (pc != NULL && pc->get_teacher_fd() == p->getfd()) 
    {
        cout << "hereeeeeeeeeeeeeeeeeeeeeeeeeeee" << endl;
        MSG_HEAD* head = (MSG_HEAD*)p->ptr();

        head->cType = iCommandType;
        p->setfd (pc->get_white_fd());
        cout << "here len = " << head->cLen << endl;
        p->setsize (head->cLen);
        SINGLE->sendqueue.enqueue (p);
    }
    else 
    {
        cout << "Error: not found 'teacher_fd' in Room" << endl;
        //cout << "not found class room" << endl;
        SINGLE->bufpool.free(p);
        return false;
    }
#endif
    return true;
}

bool CHandleMessage::postWhiteToTeacher (Buf* p, enum CommandType iCommandType)
{
#if 0
    cout << "postWhiteToTeacher ...................... " << endl;
    CRoom* pc = ROOMMANAGER->get_room_by_fd (p->getfd());

    if (pc != NULL && pc->get_white_fd() == p->getfd())
    {
        cout << "herere ... postWhiteToTeacher.... " << endl;
        MSG_HEAD* head = (MSG_HEAD*) p->ptr();
        head->cType = iCommandType;
        cout << "teacher: fddddddddddddd=" << pc->get_teacher_fd() 
            << " len: " << head->cLen 
            << " cType: " << head->cType << endl;
        cout << "data  = " << *(int*)(((char*)p->ptr()) + MSG_HEAD_LEN) << endl;
        p->setfd (pc->get_teacher_fd());
        p->setsize (head->cLen);
        SINGLE->sendqueue.enqueue (p);
    }
    else
    {
        cout << "ERROR: not found 'whiteboard_fd' in Room" << endl;
        SINGLE->bufpool.free (p);
        return false;
    }
#endif
    return true;
}

/*
=====================
 转发学生端数据到白板端
=====================
*/
bool CHandleMessage::postStudentToWhite (Buf* p, enum CommandType iCommandType)
{
#if 0
    if (p == NULL)
        return false;

    CRoom* pc = ROOMMANAGER->get_room_by_fd (p->getfd());

    if (pc != NULL && pc->get_student_by_fd (p->getfd()) != NULL) {
        MSG_HEAD* head = (MSG_HEAD*)p->ptr();

        head->cType = iCommandType;
        p->setfd (pc->get_white_fd());
        p->setsize (head->cLen);
        SINGLE->sendqueue.enqueue (p);
    }
    else {
        cout << "Error: not found 'student_fd' in Room" << endl;
        SINGLE->bufpool.free(p);
        return false;
    }
#endif
    return true;
}

/*
=====================
 转发教师端数据到所有学生端
=====================
*/
bool CHandleMessage::postTeacherToAllStudent (Buf* p, enum CommandType iCommandType)
{
#if 0
    cout << "postTeacherToAllStudent ------------------------ " <<endl;
    if (p == NULL)
        return false;

    int iLen = ((MSG_HEAD*)p->ptr())->cLen;
    int iHeadLen = sizeof (MSG_HEAD);
    Buf* pbuf = NULL;

    CRoom* pc = ROOMMANAGER->get_room_by_fd (p->getfd());
    if (pc != NULL) {

        int i = 0;
        CRoom::STUDENTMAP::iterator it;
        for (it = pc->m_student_map.begin(); \
             it != pc->m_student_map.end (); ++it)
        {
            i++;
            pbuf = SINGLE->bufpool.malloc ();
            if (pbuf != NULL) {
                MSG_HEAD* head = (MSG_HEAD*)pbuf->ptr();
                head->cLen = iLen;
                head->cType = iCommandType;
                if (iLen > iHeadLen) {
                    memcpy (head->cData(), (char*)p->ptr() + iHeadLen, iLen - iHeadLen);
                }
                pbuf->setsize (head->cLen);
                pbuf->setfd (it->first);
                SINGLE->sendqueue.enqueue (pbuf);
            }
            else {
                cout << "Error: out of memory" << endl;
                p->reset();
                pbuf->reset();
                SINGLE->bufpool.free(p);
                SINGLE->bufpool.free(pbuf);
                return false;
            }
        }
        if ( 0 == i ) {
            printf("send to %d students!\n", i);
        }
    }
    else {
        cout << __FILE__ << ":" <<__FUNCTION__<< ":" << __LINE__<<"Error: not found 'teacher_fd' in Room" << endl;
        //p->reset();
        SINGLE->bufpool.free(p);
        return false;
    }

    p->reset();
    SINGLE->bufpool.free(p);
#endif
    return true;
}

/*
=====================
 转发教师端数据到学生端
=====================
*/
bool CHandleMessage::postTeacherToStudent (Buf* p, enum CommandType iCommandType, int iStuId)
{
#if 0
    if (p == NULL)
        return false;

    CRoom* pc = ROOMMANAGER->get_room_by_fd (p->getfd());
    if (pc != NULL && pc->get_teacher_fd() == p->getfd())
    {
        CRoom::STUDENTMAP::iterator it;
        for (it = pc->m_student_map.begin(); \
             it != pc->m_student_map.end (); ++it)
        {
            if (it->second->getId() == iStuId) {
                MSG_HEAD* head = (MSG_HEAD*)p->ptr();

                head->cType = iCommandType;
                p->setfd (it->first);
                p->setsize (head->cLen);
                SINGLE->sendqueue.enqueue (p);
                cout << "send sT_LeaveEarly to student: id=" << iStuId << endl;
                return true;
            }
        }
        cout << "Error: not found 'student_fd' in Room" << endl;
        return false;
    }
    else {
        cout << "Error: not found 'teacher_fd' in Room" << endl;
        return false;
    }
#endif
    return true;
}

/*
=====================
 获得数据库表纪录数量
=====================
*/
bool CHandleMessage::postDBRecordCount (Buf* p, int iCase)
{
#if 0
    char str[1024] = "SELECT count(*) AS ccount FROM ";

    if (NULL == p) {
        printf("null buf\n");
        return false;
    }
    //printf (" postDBRecordCount ..., iCase=%d\n", iCase);
#if 1
    if (iCase == 1) {
        strcat (str, "course_group_course AS cgc, course_group AS cg, course AS c, grade AS g, grade_course AS gc WHERE  cgc.group_id = cg.group_id AND cgc.course_id = c.course_id AND gc.grade_id = g.grade_id AND c.course_id = gc.course_id");
    }
    else if (iCase == 2) {
        strcat (str, "grade");
    }
    else if (iCase == 3) {
        strcat (str, "class");
    }
    else if (iCase == 4) {
        strcat (str, "classroom");
    }
    else if (iCase == 5) {
        strcat (str, "student");
    }
    else if (iCase == 6) {
        //strcat (str, "course_item AS ci, course AS c, item AS i WHERE ci.course_id=c.course_id AND ci.item_id=i.item_id AND c.course_name=?");
        strcat (str, "course_item AS ci, course AS c, item AS i WHERE ci.course_id=c.course_id AND ci.item_id=i.item_id AND (c.course_name=? OR c.course_name=? OR c.course_name=? OR c.course_name=?)");
    }
#endif

    // dbCount.count = 100;
    //
#if 0
    struct sDBCount dbCount;
    dbCount.count = 5;
    MSG_HEAD *head = (MSG_HEAD*) buf->ptr();
    head->cLen = sizeof (MSG_HEAD) + sizeof (dbCount);
    head->cType = CT_GetClassRoomDBCount;
    memcpy (head->cData(), &dbCount, sizeof (dbCount));

    buf->setsize (head->cLen);
    SINGLE->sendqueue.enqueue (buf);
#endif
#if 1

    try {
        MutexLockGuard guard(DATABASE->m_mutex);
        PreparedStatement* pstmt = DATABASE->preStatement(str);
        if (iCase == 6) {
        #if 0 // fixed: to update
            sGetCourseItem* ci = (sGetCourseItem *) ((char*)((MSG_HEAD*)p->ptr()) + sizeof (MSG_HEAD));
            pstmt->setString (1, ci->sCourseName);
        #else
#ifdef _TEACHER_NOLOGIN
            // only for h**king test............
            pstmt->setString (1, "拼图");
            pstmt->setString (2, "造房子");
            pstmt->setString (3, "暖身操");
            pstmt->setString (4, "动画片");
#else
            CRoom* room = ROOMMANAGER->get_room_by_fd (p->getfd());
            if (room != NULL)
            {
                CRoom::COURSELIST::iterator it;
                int ii = 1;
                for (it = room->m_course_list.begin (); it != room->m_course_list.end (); ++it) {
                    pstmt->setString (ii++, (*it)->getName());
                    cout << "COURSE NAME: " << (*it)->getName() << endl;
                }
            }
#endif
        #endif
        }
        ResultSet* prst = pstmt->executeQuery ();
        while (prst->next ()) {
            struct sDBCount dbCount;
            dbCount.count = prst->getInt ("ccount");
            printf ("get db count: %d\n", dbCount.count);
            MSG_HEAD* head = (MSG_HEAD*)p->ptr();
            head->cLen = MSG_HEAD_LEN + sizeof (dbCount);

            if (iCase == 1)
                head->cType = CT_GetCourseDBCount;
            else if (iCase == 2)
                head->cType = CT_GetGradeDBCount;
            else if (iCase == 3)
                head->cType = CT_GetClassDBCount;
            else if (iCase == 4)
                head->cType = CT_GetClassRoomDBCount;
            else if (iCase == 5)
                head->cType = CT_GetAllStudentInfoCount;
            else if (iCase == 6)
                head->cType = CT_GetCourseItemCount;

            //memcpy (head->cData(), &dbCount, sizeof (dbCount));
            memcpy ((char *)p->ptr() + MSG_HEAD_LEN, &dbCount, sizeof (struct sDBCount));

            p->setsize (head->cLen);
            SINGLE->sendqueue.enqueue (p);
        }
        delete pstmt;
        delete prst;
    }
    catch (SQLException e) {
        printf ("%s\n", e.what ());
    }
#endif
#endif
    return true;
}

/*
=====================
 获得数据库表纪录
=====================
*/
bool CHandleMessage::postDBRecord (Buf* buf, int iCase)
{
#if 0
    if (NULL == buf) {
        printf("null buf\n");
        return false;
    }

    MSG_HEAD head;

    try {
        MutexLockGuard guard(DATABASE->m_mutex);
        PreparedStatement* pstmt = NULL;

        if (iCase == 1)
            pstmt = DATABASE->preStatement (SQL_SELECT_COURSE_DB);
        else if (iCase == 2)
            pstmt = DATABASE->preStatement (SQL_SELECT_GRADE_DB);
        else if (iCase == 3)
            pstmt = DATABASE->preStatement (SQL_SELECT_CLASS_DB);
        else if (iCase == 4)
            pstmt = DATABASE->preStatement (SQL_SELECT_CLASSROOM_DB);
        else if (iCase == 5)
            pstmt = DATABASE->preStatement (SQL_SELECT_STUDENT_DB);
        else if (iCase == 6) {
            pstmt = DATABASE->preStatement (SQL_SELECT_COURSEITEM_DB);
#if 1   // send count of all selected course by teacher
            #ifdef _TEACHER_NOLOGIN
            // only for h**king test............
            pstmt->setString (1, "拼图");
            pstmt->setString (2, "造房子");
            pstmt->setString (3, "暖身操");
            pstmt->setString (4, "动画片");
            #else
            CRoom* room = ROOMMANAGER->get_room_by_fd (buf->getfd());
            if (room != NULL)
            {
                CRoom::COURSELIST::iterator it;
                int ii = 1;
                for (it = room->m_course_list.begin (); it != room->m_course_list.end (); ++it)
                    pstmt->setString (ii++, (*it)->getName());
            }
            #endif
#else
            sGetCourseItem* ci = (sGetCourseItem *) ((char*)((MSG_HEAD*)buf->ptr()) + sizeof (MSG_HEAD));
            pstmt->setString (1, ci->sCourseName);
#endif
        }
        else {
            cout << "error: index" << endl;
            return false;
        }

        ResultSet* prst = pstmt->executeQuery();
        unsigned int index = 0, type = 0;
        while(prst->next()) {
            //printf ("index = %d------------------------------------------------------\n", index);
            if (iCase == 1) {
                memset (&head, 0x00, sizeof (head));
                //head.cType = CT_GetCourseDB * 100 + index++;
                type = 5000 + index++;
                memcpy (&head.cType, &type, sizeof (unsigned int));
                head.cLen = sizeof(MSG_HEAD) + sizeof(struct sGetCourseDB);
                struct sGetCourseDB course_info;
                (void) memset (&course_info, 0x00, sizeof (sGetCourseDB));

                strcpy(course_info.sGradeName, prst->getString ("grade_name").c_str());
                strcpy(course_info.sGroupName, prst->getString ("group_name").c_str());
                strcpy(course_info.sCourseName, prst->getString("course_name").c_str());

                course_info.iLanguage   = prst->getInt ("language");
                course_info.iArt        = prst->getInt ("art");
                course_info.iCommunity  = prst->getInt ("community");
                course_info.iHealth     = prst->getInt ("health");
                course_info.iScience    = prst->getInt ("science");

                Buf* p = SINGLE->bufpool.malloc ();
                memcpy(p->ptr(), &head, sizeof(MSG_HEAD));
                memcpy((char*)p->ptr() + sizeof(MSG_HEAD), &course_info, sizeof(struct sGetCourseDB));
                p->setfd(buf->getfd());
                p->setsize(head.cLen);
                SINGLE->sendqueue.enqueue(p);
            }

            else if (iCase == 2) {
                memset (&head, 0x00, sizeof (head));
                type = 3000 + index++;
                memcpy (&head.cType, &type, sizeof (unsigned int));
                //head.cType = CT_GetGradeDB;
                head.cLen = sizeof (MSG_HEAD)+ sizeof (struct sGetGradeDB);
                struct sGetGradeDB grade_info;
                (void) memset (&grade_info, 0x00, sizeof (grade_info));

                strcpy (grade_info.sGradeName, prst->getString ("grade_name").c_str());

                Buf* p = SINGLE->bufpool.malloc ();
                memcpy (p->ptr(), &head, sizeof(MSG_HEAD));
                memcpy ((char *)p->ptr() + sizeof(MSG_HEAD), &grade_info, sizeof(struct sGetGradeDB));
                p->setfd (buf->getfd ());
                p->setsize(head.cLen);
                SINGLE->sendqueue.enqueue (p);
            }

            else if (iCase == 3) {
                memset (&head, 0x00, sizeof (head));
                type = 4000 + index++;
                memcpy (&head.cType, &type, sizeof (unsigned int));
                //head.cType = CT_GetClassDB;
                head.cLen = sizeof(MSG_HEAD)+ sizeof (struct sGetClassDB);
                struct sGetClassDB class_info;
                (void) memset (&class_info, 0x00, sizeof (class_info));

                strcpy (class_info.sClassName, prst->getString ("class_name").c_str());

                Buf* p = SINGLE->bufpool.malloc ();
                memcpy (p->ptr(), &head, sizeof (MSG_HEAD));
                memcpy ((char *)p->ptr() + sizeof (MSG_HEAD), &class_info, sizeof (struct sGetClassDB));
                p->setfd (buf->getfd ());
                p->setsize(head.cLen);
                SINGLE->sendqueue.enqueue (p);
            }

            else if (iCase == 4) {
                memset (&head, 0x00, sizeof (head));
                //head.cType = CT_GetClassRoomDB;
                type = 6000 + index++;
                memcpy (&head.cType, &type, sizeof (unsigned int));
                head.cLen = sizeof(MSG_HEAD) + sizeof (struct sGetClassRoomDB);
                struct sGetClassRoomDB room_info;
                (void) memset (&room_info, 0x00, sizeof (room_info));

                strcpy (room_info.sClassRoomName, prst->getString ("classroom_name").c_str());

                Buf* p = SINGLE->bufpool.malloc ();
                memcpy (p->ptr(), &head, sizeof (MSG_HEAD));
                memcpy ((char *)p->ptr() + sizeof (MSG_HEAD), &room_info, sizeof (struct sGetClassRoomDB));
                p->setfd (buf->getfd ());
                p->setsize(head.cLen);
                SINGLE->sendqueue.enqueue (p);
            }

            else if (iCase == 5) {
                memset (&head, 0x00, sizeof (MSG_HEAD));
                type = 10000 + index++;
                memcpy (&head.cType, &type, sizeof (unsigned int));
                /// cout << "begin:-head.cType = " << head.cType << endl;
                head.cLen = sizeof (MSG_HEAD) + sizeof (struct sGetAllStudentInfo);
                struct sGetAllStudentInfo stu_info;
                (void) memset (&stu_info, 0x00, sizeof (stu_info));

                strcpy (stu_info.sPicName, prst->getString ("picture_name").c_str());
                strcpy (stu_info.sStudentName, prst->getString ("student_name").c_str());
                stu_info.iStudentId= prst->getInt ("student_id");

                /// cout << "stu_info.iStudentId:" << stu_info.iStudentId << endl;
                /// cout << "stu_info.sPicName:" << stu_info.sPicName << endl;
                /// cout << "stu_info.sStudentName:" << stu_info.sStudentName << endl;

                Buf* p = SINGLE->bufpool.malloc ();
                memcpy (p->ptr(), &head, sizeof (MSG_HEAD));
                memcpy ((char *)p->ptr() + sizeof (MSG_HEAD), &stu_info, sizeof (struct sGetAllStudentInfo));
                p->setfd (buf->getfd ());
                p->setsize(head.cLen);
                SINGLE->sendqueue.enqueue (p);
                /// cout << "address = " << p << endl;
                /// cout << "ended:-head.cLen = " << head.cLen << endl;
                /// cout << "ended:-head.cType = " << head.cType << endl;
            }

            else if (iCase == 6) {
                memset (&head, 0x00, sizeof (head));
                type = 7000 + index++;
                memcpy (&head.cType, &type, sizeof (unsigned int));
                //head.cType = CT_GetCourseItem;
                head.cLen = sizeof(MSG_HEAD) + sizeof (struct sCourseItem);
                struct sCourseItem course_item;
                (void) memset (&course_item, 0x00, sizeof (sCourseItem));

                strcpy (course_item.sCourseName, prst->getString ("course_name").c_str());
                strcpy (course_item.sItemName, prst->getString ("item_name").c_str());
                strcpy (course_item.sDesc, prst->getString ("fck_desc").c_str());

                cout << "courseName: " << course_item.sCourseName << endl;
                cout << "itemName: " << course_item.sItemName << endl;
                cout << "Desc: " << course_item.sDesc << endl;
                Buf* p = SINGLE->bufpool.malloc ();
                memcpy (p->ptr(), &head, sizeof(MSG_HEAD));
                memcpy ((char *)p->ptr() + sizeof(MSG_HEAD), &course_item, sizeof (struct sCourseItem));
                p->setfd (buf->getfd ());
                p->setsize(head.cLen);
                SINGLE->sendqueue.enqueue (p);
            }
            else {
                cout << "error: index" << endl;
                return false;
            }

        }
#if 1   // send finished flags
        do {
            sleep (1);
            //cout << "send finished flags -----------" << endl;
            Buf* p = SINGLE->bufpool.malloc ();
            MSG_HEAD* phead = (MSG_HEAD*)p->ptr();
            struct sDBRecordFinished finished;
            memset (&finished, 0x00, sizeof (sDBRecordFinished));
            if (iCase == 5)
                finished.iFlagFinished = 10000;
            else
                finished.iFlagFinished = 1;

            phead->cLen = sizeof (MSG_HEAD) + sizeof (struct sDBRecordFinished);
            phead->cType = ST_GetDBRecordFinished;
            memcpy (((char*)p->ptr()) + MSG_HEAD_LEN, &finished, sizeof (struct sDBRecordFinished));
            p->setfd (buf->getfd());
            p->setsize (phead->cLen);
            SINGLE->sendqueue.enqueue (p);
        } while (0);
#endif
    }
    catch(SQLException e){
        LOG(ERROR) << e.what() << std::endl;
    }

    buf->reset();
    SINGLE->bufpool.free(buf);
#endif
    return true;
}
