
/*
 * client.cpp
 */

#include "client.h"

CClient::CClient ()
{
}

CClient::~CClient ()
{
}

void CClient::setOnLine (bool b)
{
    m_onLine = b;
}

bool CClient::getOnLine (void)
{
    return (m_onLine);
}

void CClient::setId (int id)
{
    m_Id = id;
}

int CClient::getId ()
{
    return (m_Id);
}

void CClient::setSocket (int sock)
{
    m_Socket = sock;
}

int CClient::getSocket ()
{
    return (m_Socket);
}

void CClient::setVersion (const string& ver)
{
    m_version = ver;
}

string CClient::getVersion (void)
{
    return (m_version);
}

void CClient::setIpAddr (const string& ip)
{
    m_IpAddr = ip;
}

string CClient::getIpAddr (void)
{
    return (m_IpAddr);
}
