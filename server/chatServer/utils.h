
/*
 * Written 2013 by fU9ANg
 * bb.newlife@gmail.com
 */

#ifndef _CHAT_UTILS_H
#define _CHAT_UTILS_H

void outLog (char* buf, ...);

#ifndef WIN32
DWORD   getTime ();
#endif

/* prototype */
void  putByte    (char* pPacket, BYTE  value, int& nPos);
BYTE  getByte    (char* pPacket, int& nPos);
void  putWord    (char* pPacket, WORD  value, int& nPos);
WORD  getWord    (char* pPacket, int& nPos);

void  putDWord   (char* pPacket, DWORD value, int& nPos);
DWORD getDWord   (char* pPacket, int& nPos);
void  putInteger (char* pPacket, int   value, int& nPos);
int   getInteger (char* pPacket, int& nPos);
void  putShort   (char* pPacket, short value, int& nPos);
short getShort   (char* pPacket, int& nPos);
void  putString  (char* pPacket, char* value, int& nPos);
void  getString  (char* pPacket, char* value, int& nPos);

void  putSize(char* pPacket, WORD nPos);

#endif  //_CHAT_UTILS_H
