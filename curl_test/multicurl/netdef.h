#ifndef	__NETDEF_H__
#define __NETDEF_H__

#ifndef IS_SERVER
//#	define IS_SERVER
#endif

// for Buf.h
#ifndef BUF_MAX_SIZE
#    define BUF_MAX_SIZE	(4096)
#endif

#ifndef BUF_INVALIED_FD
#    define BUF_INVALIED_FD	(-1)
#endif

#ifndef BUF_INVALIED_ID
#    define BUF_INVALIED_ID	(-1)
#endif

// for PoolT.h
#ifndef POOLT_MAX_SIZE
#    define POOLT_MAX_SIZE	(2000)
#endif

// for MsgReceiver.cpp
#ifndef MSGRECEIVER_SERV_IP
//#    define MSGRECEIVER_SERV_IP	("192.168.0.194")
#    define MSGRECEIVER_SERV_IP	("192.168.0.145")
#endif

#ifndef MSGRECEIVER_SERV_PORT
#    define MSGRECEIVER_SERV_PORT	(9999)
#endif

// for global_functions.h
#ifndef GLOBAL_FUNC_INVALIED_FD
#	ifdef IS_SERVER
#		define GLOBAL_FUNC_INVALIED_FD	(-1)
#	else
#		define GLOBAL_FUNC_INVALIED_FD	(MsgReceiver::g_socket.getSocketFd())
#	endif
#endif

#ifndef GROUP_NAME_LEN
#	define GROUP_NAME_LEN	(128)
#endif

#ifndef TRUE
#	define TRUE	(1)
#endif

#ifndef FALSE
#	define FALSE	(2)
#endif

#ifndef PKG_CNT
#	define PKG_CNT	(5)
#endif

#endif // __NETDEF_H__
