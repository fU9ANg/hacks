
/**
 * ingroup database database
 * @{
 */ 

#ifndef _ECSERVER_DATABASE_H_
#define _ECSERVER_DATABASE_H_

#include <string>
#include <iostream>

#include "mysql/mysql_connection.h"
#include "mysql/mysql_driver.h"
#include "mysql/cppconn/resultset.h"
#include "mysql/cppconn/driver.h"
#include "mysql/cppconn/exception.h"
#include "mysql/cppconn/resultset.h"
#include "mysql/cppconn/statement.h"
#include "mysql/cppconn/prepared_statement.h"

#include "glog/logging.h"

#include "Config.h"
#include "Mutex.h"

using namespace sql;
using namespace std;

class DataBase
{
    public:
        ~DataBase ();
        /**
         * @brief init the connection with mysql
         * @param[in] host      address of mysql
         * @param[in] username  username of mysql
         * @param[in] password  password of mysql
         * @param[in] database  database of mysql
         * @retval    true      success
         * @retval    false     faild
         */
        bool Init (string host, string username, string password, string database);

        /**
         * @brief get a Connection of mysql
         */
        Connection* getConnection ();

        /**
         * @brief get a Statement of mysql
         */
        Statement* getStatement ();

        /**
         * @brief get a prepare Statement of mysql
         */
        PreparedStatement* preStatement (string sql);

        static DataBase* instance ();
        MutexLock m_mutex;

    private:
        DataBase ();
        Driver* m_pDriver;
        Connection* m_pConn;
        string m_host;
        string m_user_name;
        string m_password;
        string m_database;
        static DataBase *pinstance;
};

#define DATABASE DataBase::instance()
#endif

/**
 * @}
 */
