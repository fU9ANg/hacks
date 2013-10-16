/*
   @desc		the implement of db class @author fU9ANg
   @date		2013/04/25
   @copyright	bb.newlife@gmail.com
   */

#include "database.h"

DataBase* DataBase::pinstance = NULL;

// init function
bool DataBase::Init (string host, string user_name, string password, string database)
{
    m_host      = host;
    m_user_name = user_name;
    m_password  = password;
    m_database  = database;

    try
    {
        m_pDriver = get_driver_instance ();
        m_pConn = m_pDriver->connect (m_host, m_user_name, m_password);
        m_pConn->setSchema (database);
    }
    catch (SQLException e)
    {
        LOG(ERROR) << e.what ();
        printf ("Database Info =[%s]\n", e.what ());
        m_pConn = NULL;
    }
    return  (NULL == m_pConn) ? false:true;
}

DataBase::DataBase ()
{
    m_pConn = NULL;
}

DataBase::~DataBase ()
{
    if  (NULL != m_pConn)
    {
        delete m_pConn;
        m_pConn = NULL;
    }
}

Connection* DataBase::getConnection ()
{
    return m_pConn;	
}

Statement* DataBase::getStatement ()
{
    Statement* p = NULL;
    try
    {
        p = m_pConn->createStatement (); 
    }
    catch  (SQLException e)
    {
        LOG(ERROR) << e.what ();
        if (NULL != p )
        {
            delete p;
            p = NULL;
        }
    }
    return p;
}

PreparedStatement* DataBase::preStatement (string sql)
{
    return m_pConn->prepareStatement (sql); 
}

DataBase* DataBase::instance ()
{
    if  ( NULL == pinstance)
    {
        pinstance = new DataBase ();
    }
    return pinstance;
}
