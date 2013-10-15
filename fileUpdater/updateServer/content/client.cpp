
/*
 * client.cpp
 */

#include "client.h"

CClient::CClient () {
    isBuildHouseFinished = 0;
}

CClient::~CClient () {
}

void CClient::setName (string& s1, string& s2) {
    m_StuName = s1 + s2;
}

string CClient::getName (void) {
    return m_StuName;
}

void CClient::setAccount (string& acc) {
    m_AccountName = acc;
}

string CClient::getAccount (void) {
    return m_AccountName;
}

void CClient::setPassword (string& pwd)
{
    m_Password = pwd;
}

string CClient::getPassword (void)
{
    return (m_Password);
}

void CClient::setOnLine (bool b) {
    m_onLine = b;
}

bool CClient::getOnLine (void) {
    return m_onLine;
}

void CClient::setId(int id) {
    m_Id = id;
}

int CClient::getId() {
    return m_Id;
}

void CClient::setSocket(int sock) {
    m_Socket = sock;
}

int CClient::getSocket() {
    return m_Socket;
}

void CClient::setPictureName (string name)
{
    this->m_picture_name = name;
}

string CClient::getPictureName (void)
{
    return this->m_picture_name;
}

eClientStatus CClient::getStudentStatus (void)
{
    return m_current_status;
}

void CClient::setStudentStatus (eClientStatus ess)
{
    m_current_status = ess;
}
