#ifndef __GLOBAL_FUNCTIONS_H__
#define __GLOBAL_FUNCTIONS_H__

#include "protocol.h"
#include "Single.h"

namespace {

/*
template <typename T>
Buf* package(const enum CommandType msg_type, const T& obj) {
	MSG_HEAD header;
	header.cType = msg_type;
	header.cLen = sizeof(T) + MSG_HEAD_LEN + sizeof(int);

	Buf* pBuf = SINGLE->bufpool.malloc();
	pBuf->reset();
	memcpy(pBuf->ptr(), &header, sizeof(header));
	*(int*)((char*)pBuf->ptr() + MSG_HEAD_LEN) = 1;
	memcpy(((char*)pBuf->ptr())+sizeof(header)+sizeof(int), &obj, sizeof(obj));

	pBuf->set_size(header.cLen);

	return pBuf;
}

template <typename T>
T& unpackage(Buf* pBuf, T&, int cnt = 0) {
	return *(T*) (((char*)pBuf->ptr()) + sizeof(MSG_HEAD) + sizeof(int) + sizeof(T)*cnt);
}

static int unpack_cnt(Buf* pBuf) {
	return *(int*)((char*)pBuf->ptr() + MSG_HEAD_LEN);
}

static Buf* combine_buf(Buf* dist, Buf** src) {
	if (NULL == dist && NULL == *src) {
		return NULL;
	}

	if (NULL == dist) {
		return *src;
	}

	if (NULL == *src) {
		return dist;
	}

	if (((MSG_HEAD*)dist->ptr())->cType != ((MSG_HEAD*)(*src)->ptr())->cType) {
		return NULL;
	} else {
		MSG_HEAD* dist_head = (MSG_HEAD*)dist->ptr();
		MSG_HEAD* src_head = (MSG_HEAD*)(*src)->ptr();

		*(int*)((char*)dist->ptr() + MSG_HEAD_LEN) = unpack_cnt(dist) + unpack_cnt(*src);
		memcpy((char*)dist->ptr()+dist_head->cLen \
				, (char*)(*src)->ptr()+MSG_HEAD_LEN+sizeof(int) \
				, src_head->cLen - MSG_HEAD_LEN - sizeof(int));

		dist_head->cLen = dist_head->cLen + src_head->cLen - MSG_HEAD_LEN - sizeof(int);
		SINGLE->bufpool.free(*src);
		*src = NULL;

		return dist;
	}
}
*/

static int
unpacket_cnt(Buf* pBuf) {
        if (NULL == pBuf) {
                return -1;
        } else  {
                return *(int*)((char*)pBuf->ptr() + MSG_HEAD_LEN);
        }
}

static Buf*
packet_head(enum CommandType type, const int obj_size, const int cnt, const int fd) {
	Buf* pBuf = SINGLE->bufpool.malloc();
        if (NULL == pBuf) { // 内存分配失败。
#ifdef __DEBUG__
                printf("[DEBUG] %s : NULL == pBuf\n", __func__);
#endif
                return NULL;
        }

	MSG_HEAD* head = (MSG_HEAD*)pBuf->ptr();
	head->cType = type;
	head->cLen = MSG_HEAD_LEN + sizeof(int) + obj_size*cnt;
	*(int*)((char*)pBuf->ptr() + MSG_HEAD_LEN) = cnt;
#ifdef __DEBUG__
        // printf("[DEBUG] %s : *(int*)((char*)pBuf->ptr() + MSG_HEAD_LEN) = %d\n", __func__, *(int*)((char*)pBuf->ptr() + MSG_HEAD_LEN));
#endif

        pBuf->setsize(head->cLen);
        pBuf->setfd(fd);

        return pBuf;
        unpacket_cnt(NULL);
}

template <typename T> Buf*
packet_list(enum CommandType type, T& obj, const int fd) {
        std::string send_buf;
        if (!obj.SerializePartialToString(&send_buf)) {
#ifdef __DEBUG__
                printf("[DEBUG] %s : SerializeToString fail.\n", __func__);
#endif
                return NULL;
        } else {
                int obj_size = send_buf.size();
                Buf* pBuf = packet_head(type, obj_size, 1, fd);
                if (NULL == pBuf) {
#ifdef __DEBUG__
                        printf("[DEBUG] %s : NULL == pBuf\n", __func__);
#endif
                        return NULL;
                } else {
                        memcpy(((char*)pBuf->ptr())+MSG_HEAD_LEN+sizeof(int), send_buf.c_str(), send_buf.size());
                        return pBuf;
                }
        }
}

template <typename T> bool
unpacket(Buf* pBuf, T& obj, int cnt = 0) {
        std::string recv_buf = (char*)pBuf->ptr() + MSG_HEAD_LEN + sizeof(int) + sizeof(T)*cnt;
        bool flag = obj.ParseFromString(recv_buf);
        (void)flag;
#ifdef __DEBUG__
        // printf("[DEBUG] unpacket : flag = %s\n", flag ? "true" : "false");
#endif
        return true;
}

static Buf*
packet(enum CommandType type, int fd) {
        return packet_head(type, 0, 0, fd);
}

template <typename T> Buf*
packet(enum CommandType type, const T& obj, int fd) {
        std::string send_buf;
        if (!obj.SerializeToString(&send_buf)) {
#ifdef __DEBUG__
                printf("[DEBUG] %s : SerializeToString fail.\n", __func__);
#endif
                return NULL;
        } else {
                // int obj_size = sizeof(obj);
                int obj_size = send_buf.size();
                Buf* pBuf = packet_head(type, obj_size, 1, fd);
                if (NULL == pBuf) { // 内存分配失败。
#ifdef __DEBUG__
                        printf("[DEBUG] %s : NULL == pBuf\n", __func__);
#endif
                        return NULL;
                }
                memcpy(((char*)pBuf->ptr())+MSG_HEAD_LEN+sizeof(int), send_buf.c_str(), send_buf.size());
                return pBuf;
        }
}

template <typename T> Buf*
packet(enum CommandType type, std::vector<T>& vc, int fd) {
        Buf* pBuf = packet_head(type, sizeof(vc[0]), vc.size(), fd);
        if (NULL == pBuf) { // 内存分配失败。
#ifdef __DEBUG__
                printf("[DEBUG] %s : NULL == pBuf\n", __func__);
#endif
                return NULL;
        }

        for (int i=0; i<(signed)vc.size(); ++i) {
                std::string send_buf;
                vc[i].SerializeToString(&send_buf);
                printf("[INFO] packet : send_buf.size() = %d\n", (signed)send_buf.size());
                memcpy(((char*)pBuf->ptr())+MSG_HEAD_LEN+sizeof(int)+128*i
                                , send_buf.c_str(), send_buf.size());
        }
        return pBuf;
}

template <> Buf*
packet(enum CommandType type, std::vector<int>& vc, int fd) {
        Buf* pBuf = packet_head(type, sizeof(vc[0]), vc.size(), fd);
        if (NULL == pBuf) { // 内存分配失败。
#ifdef __DEBUG__
                printf("[DEBUG] %s : NULL == pBuf\n", __func__);
#endif
                return NULL;
        }

        std::string send_buf;
        for (int i=0; i<(signed)vc.size(); ++i) {
                memcpy(((char*)pBuf->ptr())+MSG_HEAD_LEN+sizeof(int)+sizeof(vc[0])*i \
                                , &vc[i], sizeof(vc[0]));
        }

        SINGLE->bufpool.free(packet(type, 0));
        return pBuf;
}

/*
   static Buf*
   combine_buf(Buf* dist, Buf** src) {
   if (NULL == dist && NULL == *src) {
   return NULL;
   }

   if (NULL == dist) {
   return *src;
   }

   if (NULL == *src) {
   return dist;
   }

   if (((MSG_HEAD*)dist->ptr())->cType != ((MSG_HEAD*)(*src)->ptr())->cType) {
   return NULL;
   } else {
   MSG_HEAD* dist_head = (MSG_HEAD*)dist->ptr();
   MSG_HEAD* src_head  = (MSG_HEAD*)(*src)->ptr();

 *(int*)((char*)dist->ptr() + MSG_HEAD_LEN) = unpacket_cnt(dist) + unpacket_cnt(*src);
 memcpy((char*)dist->ptr()+dist_head->cLen \
 , (char*)(*src)->ptr()+MSG_HEAD_LEN+sizeof(int) \
 , src_head->cLen - MSG_HEAD_LEN - sizeof(int));

 dist_head->cLen = dist_head->cLen + src_head->cLen - MSG_HEAD_LEN - sizeof(int);
 SINGLE->bufpool.free(*src);
 *src = NULL;

 return dist;
 }
 }
 */

}; // end of namespace

#endif // __GLOBAL_FUNCTIONS_H__
