#ifndef	__NETDEF_H__
#define __NETDEF_H__

#ifndef __DEBUG__
#       define __DEBUG__
#endif

// for Buf.h
#ifndef BUF_MAX_SIZE
#    define BUF_MAX_SIZE	(512)
#endif

#ifndef BUF_INVALIED_FD
#    define BUF_INVALIED_FD	(-1)
#endif

#ifndef BUF_INVALIED_ID
#    define BUF_INVALIED_ID	(-1)
#endif

// for PoolT.h
#ifndef POOLT_MAX_SIZE
#    define POOLT_MAX_SIZE	(20000)
#endif

// for MsgReceiver.cpp
#ifndef MSGRECEIVER_SERV_IP
#    define MSGRECEIVER_SERV_IP	("192.168.0.194")
#endif

#ifndef MSGRECEIVER_SERV_PORT
#    define MSGRECEIVER_SERV_PORT	(8888)
#endif

// for epClass.h
#ifndef EPCLASS_INVALID_CLASS_ID
#       define EPCLASS_INVALID_CLASS_ID (-1)
#endif

// for epSchool.h
#ifndef EPSCHOOL_INVALID_SCHOOL_ID
#       define EPSCHOOL_INVALID_SCHOOL_ID      (-1)
#endif

// for epClassroom.h
#ifndef EPCLASSROOM_INVALID_CLASSROOM_ID
#       define EPCLASSROOM_INVALID_CLASSROOM_ID (-1)
#endif

#ifndef EPCLASSROOM_MAX_COURSEWARE_IDX
#       define EPCLASSROOM_MAX_COURSEWARE_IDX (32)
#endif

// for epPerson.h
#ifndef EPPERSON_INVALID_PERSON_AGE
#       define EPPERSON_INVALID_PERSON_AGE      (-1)
#endif

// for epTeacher.h
#ifndef EPTEACHER_INVALID_TEACHER_ID
#       define EPTEACHER_INVALID_TEACHER_ID     (-1)
#endif

// for epStudent.h
#ifndef EPSTUDENT_INVALIED_STUDENT_ID
#       define EPSTUDENT_INVALIED_STUDENT_ID    (-1)
#endif

// for epWhiteBoard.h
#ifndef EPWHITEBOARD_INVALID_WHITEBOARD_ID
#       define EPWHITEBOARD_INVALID_WHITEBOARD_ID       (-1)
#endif

// for epGroup.h
#ifndef EPGROUP_INVALID_GROUP_ID
#       define EPGROUP_INVALID_GROUP_ID (-1)
#endif

// for epUser.cpp
#ifndef EPUSER_INVALID_USER_ID
#       define EPUSER_INVALID_USER_ID   (-1)
#endif

#ifndef EPUSER_INVALID_USER_FD
#       define EPUSER_INVALID_USER_FD (-1)
#endif

#ifndef GROUP_NAME_LEN
#       define GROUP_NAME_LEN (128)
#endif

#ifndef TRUE
#       define TRUE     (1)
#endif

#ifndef FALSE
#       define FALSE   (2)
#endif

#define DEBUG_INFO printf("[DEBUG] file=%s : func=%s : line=%d\n", __FILE__, __func__, __LINE__);
#define RETURN(_p) SINGLE->bufpool.free(_p); return
#define CHECK_P(_p) if (NULL == _p) { DEBUG_INFO; RETURN(p); }
#define UNPACKET(_p, tmp) if (!unpacket(_p, tmp)) { DEBUG_INFO; RETURN(_p); }

// for handler
#define CHECK_BUF(dist, src) \
        if (NULL == dist) { \
                DEBUG_INFO; \
                SINGLE->bufpool.free(src); \
        }


#define CLONE_BUF(dist, src) \
        dist = SINGLE->bufpool.malloc(); \
        CHECK_BUF(dist, src) \
        dist->setfd(src->getfd()); \
        dist->setsize(src->size()); \
        memcpy(dist->ptr(), src->ptr(), dist->size())

#define SET_OPTION(cn, type, obj) \
        if (0 != prst->get##type(#obj)) { \
                cn->set_##obj(prst->get##type(#obj)); \
        }

#define MOVE_USER_TO_USER_MAP(p_user) \
        if (NULL != p_user) { \
                if (US_OFFLINE == p_user->userStatus_) { \
                        delete p_user; \
                        p_user = NULL; \
                } else { \
                        p_user->funcType_ = FT_INVALID; \
                        EPMANAGER->insertUser(p_user->fd_, p_user); \
                } \
        }

#define PRINT_CATCH(obj) printf("[DEBUG] file=%s : func=%s : line=%d, exception = %s\n", __FILE__, __func__, __LINE__, obj.what());

#define PROCEDURE_SUCCESS_RESULT "success"

#endif // __NETDEF_H__
