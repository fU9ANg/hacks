
/**
 * @file Buf.h
 */

#ifndef _ECSERVER_BUF_H_
#define _ECSERVER_BUF_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define     MAX_BUF     5120

class Buf 
{
public:
    Buf (size_t inSize = MAX_BUF)
    {
        m_size  = inSize;
        m_ptr   = malloc (m_size);
        m_fd    = 0;
        m_id    = 0;
    };

    ~Buf ()
    {
        if  (m_ptr != NULL)
        {
            free (m_ptr);
            m_ptr = NULL;
        }
    }

    Buf (Buf& b)
    {
        m_size = b.m_size;
        this->m_ptr = malloc (m_size);
        memcpy (this->m_ptr, b.m_ptr, m_size);
    };

    void* ptr ()
    {
        return m_ptr;
    }

    size_t setsize (size_t in)
    {
        return m_used = in;
    }

    size_t maxsize ()
    {
        return m_size;
    }

    size_t size ()
    {
        return m_used;
    }

    void reset ()
    {
        memset (m_ptr, 0x00, m_size);
    }

    int getfd ()
    {
        return m_fd;
    }

    void setfd (int fd)
    {
        m_fd = fd;
    }

    int getid ()
    {
        return m_id;
    }

    void setid (int id)
    {
        m_id = id;
    }

    Buf& operator=  (Buf& b)
    {
        memcpy (this->m_ptr, b.ptr (), m_size);
        return *this;
    }

private:
    void*   m_ptr;
    size_t  m_size;
    size_t  m_used;
    int     m_fd;
    int     m_id;
};

#endif  // _ECSERVER_BUF_H
