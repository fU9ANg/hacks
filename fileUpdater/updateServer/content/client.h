
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
    eClientStatus m_current_status;
	string        m_StuName;
    string        m_Password;
	string        m_AccountName;
	bool          m_onLine;
    int           m_Id;
    int           m_Socket;
    string        m_picture_name;

public:
    eClientStatus getStudentStatus (void);
    void setStudentStatus (eClientStatus ess);
public:
	CClient ();
	CClient (string& s1, string& s2, string& acc, bool line):\
		m_StuName (s1+s2), m_AccountName (acc), m_onLine (line) {}
	~CClient ();

	void setName (string& s1, string& s2);
	string getName (void);

	void setAccount (string& acc);
	string getAccount (void);

    void setPassword (string& pwd);
    string getPassword (void);

	void setOnLine (bool b);
	bool getOnLine (void);

    void setId(int id);
    int getId();

    void setSocket(int sock);
    int getSocket();

    void setPictureName (string name);
    string getPictureName (void);

    int  isBuildHouseFinished;
};

#endif //_CCLIENT_H
