
/*
 * client.h
 */

#ifndef	_CCLIENT_H
#define _CCLIENT_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <iostream>
#include "protocol.h"

using namespace std;

class CClient
{
private:
	bool          m_onLine;
    int           m_Id;
    int           m_Socket;
    string        m_version;
    string        m_IpAddr;

public:
	CClient ();
	CClient (bool line) : m_onLine (line) {}
	~CClient ();

	void setOnLine (bool b);
	bool getOnLine (void);

    void setId (int id);
    int  getId ();

    void setSocket (int sock);
    int  getSocket ();

    void setVersion (const string& ver);
    string getVersion (void);

    void setIpAddr (const string& ip);
    string getIpAddr (void);
};

#endif //_CCLIENT_H
