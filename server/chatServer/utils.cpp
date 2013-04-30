
#include "define.h"
#include "utils.h"
#include <stdarg.h>

/*
====================
 printf logging to file
====================
*/
void outLog (char* buf, ...)
{
    char tmp_buf[1024], tmp_buf2[1024];

    va_list args;
    FILE* fp;

    time_t tval;
    time (&tval);

    struct tm* currTM = localtime (&tval);

    fp = fopen ("log.txt", "a");
    if (!fp)
        return;

    va_start (args, buf);
    vsprintf (tmp_buf, buf, args);
    va_end (args);

    sprintf (tmp_buf2, "[%d/%02d/%02d %02d:%02d:%02d]%s",
            currTM->tm_year + 1900,
            currTM->tm_mon + 1,
            currTM->tm_mday,
            currTM->tm_hour,
            currTM->tm_min,
            currTM->tm_sec,
            tmp_buf);

    strcpy (tmp_buf, tmp_buf2);

    (void) fprintf (fp, "%s", tmp_buf);

#ifndef WIN32
    (void) printf ("%s", tmp_buf);
#endif
    if (fp)
        fclose (fp);
}

#ifndef WIN32

/*
====================
 get current time of system
====================
*/
DWORD getTime ()
{
    struct timeval tv;
    gettimeofday (&tv, NULL);
    DWORD value = (((tv.tv_sec - 1000000000) * 1000) + (tv.tv_usec / 1000));
    return (value);
}

void  putByte (char* pPacket, BYTE  value, int& nPos)
{
    *(BYTE*) (pPacket + nPos) = value;
    nPos += sizeof (BYTE);
}

BYTE  getByte (char* pPacket, int& nPos)
{
    BYTE value = *(BYTE*) (pPacket + nPos);
    nPos += sizeof (BYTE);

    return (value);
}

void  putWord (char* pPacket, WORD  value, int& nPos)
{
    *(WORD*) (pPacket + nPos) = value;
    nPos += sizeof (WORD);
}

WORD  getWord (char* pPacket, int& nPos)
{
    WORD value = *(WORD*) (pPacket + nPos);
    nPos += sizeof (WORD);

    return (value);
}

void  putDWord (char* pPacket, DWORD value, int& nPos)
{
    *(DWORD*) (pPacket + nPos) = value;
    nPos += sizeof (DWORD);
}

DWORD getDWord (char* pPacket, int& nPos)
{
    DWORD value = *(DWORD*) (pPacket + nPos);
    nPos += sizeof (DWORD);

    return (value);
}

void  putInteger (char* pPacket, int   value, int& nPos)
{
    *(int*) (pPacket + nPos) = value;
    nPos += sizeof (int);
}

int   getInteger (char* pPacket, int& nPos)
{
    int value = *(int*) (pPacket + nPos);
    nPos += sizeof (int);

    return (value);
}

void  putShort (char* pPacket, short value, int& nPos)
{
    *(short*) (pPacket + nPos) = value;
    nPos += sizeof (short);
}

short getShort (char* pPacket, int& nPos)
{
    short value = *(short*) (pPacket + nPos);
    nPos += sizeof (short);

    return (value);
}

void  putString (char* pPacket, char* value, int& nPos)
{
    *(WORD*) (pPacket + nPos) = strlen (value);

    nPos += sizeof (WORD);

    (void) memcpy (pPacket + nPos, value, strlen (value));
    nPos += strlen (value);
}

void  getString (char* pPacket, char* value, int& nPos)
{
    WORD buff_len;

    buff_len = *(WORD*) (pPacket + nPos);
    nPos += sizeof (WORD);
    (void) memcpy (value, pPacket + nPos, buff_len);
    *(value + buff_len) = 0x00;
    nPos += buff_len;
}

void  putSize (char* pPacket, WORD nPos)
{
    *(WORD*) pPacket = nPos;
}

#endif
