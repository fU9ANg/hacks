#ifndef __BUF_H__
#define __BUF_H__

#include <string.h> // for memcpy and memset
#include <stdio.h>  // for printf
#include <stdlib.h> // for malloc and free
#include "netdef.h" // for some macro

class Buf {
public :
	Buf(size_t inSize = BUF_MAX_SIZE)
		: m_ptr()
		  , m_fileptr()
		  , m_size(inSize)
		  , m_fd(BUF_INVALIED_FD)
		  , m_id(BUF_INVALIED_ID)
	{
		m_ptr   = malloc (m_size);
		if (NULL == m_ptr) {
			printf("[ERROR] file = %s\nfunc = %s\nline = %d\n", __FILE__, __func__, __LINE__);
		}

		m_fileptr = malloc (m_size);
		if (NULL == m_fileptr) {
			printf("[ERROR] file = %s\nfunc = %s\nline = %d\n", __FILE__, __func__, __LINE__);
		}
		reset ();
	}

	Buf(const Buf& rhs)
		: m_ptr()
		  , m_fileptr()
		  , m_size(rhs.m_size)
		  , m_fd(rhs.m_fd)
		  , m_id(rhs.m_id)
	{
		this->m_ptr = malloc (rhs.m_size);
		if (NULL != this->m_ptr) {
			memcpy (this->m_ptr, rhs.m_ptr, m_size);
		} else {
			printf("[ERROR] file = %s\nfunc = %s\nline = %d\n", __FILE__, __func__, __LINE__);
		}

		this->m_fileptr = malloc (rhs.m_size);
		if (NULL != this->m_fileptr) {
			memcpy (this->m_fileptr, rhs.m_fileptr, m_size);
		}
		else {
			printf("[ERROR] file = %s\nfunc = %s\nline = %d\n", __FILE__, __func__, __LINE__);
		}
	}

	~Buf(void) {
		if (NULL != m_ptr) {
			free (m_ptr);
			m_ptr = NULL;
		}

		if (NULL != m_fileptr) {
			free (m_fileptr);
			m_fileptr = NULL;
		}
	}

	void* ptr (void) const {
		return m_ptr;
	}

	void* fileptr(void) const {
		return m_fileptr;
	}

	size_t set_size (size_t in) {
		return m_used = in;
	}

	size_t max_size (void) const {
		return m_size;
	}

	size_t get_size(void) const {
		return m_used;
	}

	void reset(void) {
		memset(m_ptr, 0x00, m_size);
		memset(m_fileptr, 0x00, m_size);
	}

	int get_fd(void) const {
		return m_fd;
	}

	void set_fd (int fd) {
		m_fd = fd;
	}

	int get_id(void) const {
		return m_id;
	}

	void setid(int id) {
		m_id = id;
	}

	const Buf& operator=(const Buf& rhs) {
		if (this != &rhs) {
			m_size = rhs.m_size;
			m_fd   = rhs.m_fd;
			m_id   = rhs.m_id;
			m_used = rhs.m_used;
			memcpy(this->m_ptr, rhs.ptr(), m_size);
		}
		return *this;
	}

private:
	void*   m_ptr;
	void*   m_fileptr;
	size_t  m_size;
	size_t  m_used;
	int     m_fd;
	int     m_id;
};

#endif // __BUF_H__
