
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

void  PutByte    (char* pPacket, BYTE  value, int& nPos);
BYTE  GetByte    (char* pPacket, int& nPos);
void  PutWord    (char* pPacket, WORD  value, int& nPos);
WORD  GetWord    (char* pPacket, int& nPos);

void  PutDWord   (char* pPacket, DWORD value, int& nPos);
DWORD GetDWord   (char* pPacket, int& nPos);
void  PutInteger (char* pPacket, int   value, int& nPos);
int   GetInteger (char* pPacket, int& nPos);
void  PutShort   (char* pPacket, short value, int& nPos);
short GetShort   (char* pPacket, int& nPos);
void  PutString  (char* pPacket, char* value, int& nPos);
void  GetString  (char* pPacket, char* value, int& nPos);

void  PutSize(char* pPacket, WORD nPos);

#endif  //_CHAT_UTILS_H
