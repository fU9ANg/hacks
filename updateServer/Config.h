/**
 * @addtogroup framework
 * @{
 */

#ifndef _ECSERVER_CONFIG_H_
#define _ECSERVER_CONFIG_H_

#include <stdio.h>
#include <string>

#include "lua5.2/lua.hppp"

using namespace std;

/**
 * @class 配置文件类
 */
class Config
{
    public:
        ~Config ();
        static class Config* instance ();
        /**
         * @brief 读取配置文件
         * @param file 配置文件路径
         */
        void readconfig (string file);

    public:
        string  db_host;
        string  db_username;
        string  db_password;
        string  db_database;
        string  server_ip;
	string  username;
	string  passwd;

        int     server_port;
        int     school_id;
        int     game_count;

    private:
        Config();
        static class Config* m_config;
};

#define CONFIG Config::instance()
#endif

///@}
