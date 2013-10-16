
#include "Config.h"

Config* Config::m_config = NULL;

Config* Config::instance ()
{
    if  (NULL == m_config)
    {
        m_config = new Config (); 
    }
    return m_config;
}

Config::Config ()
{
    //TODO:
}
    
Config::~Config ()
{
    //TODO:
}

void Config::readconfig (string file)
{
  lua_State* lua = luaL_newstate ();

  //加载脚本
  //int ret = luaL_loadfile (lua, "config.lua");
  int ret = luaL_loadfile (lua, file.c_str ());
  if (ret != 0)
  {
    lua_close (lua);
    return;
  }   
  //初始化
  ret = lua_pcall (lua, 0, 0, 0);
  if (ret != 0)
  {
    lua_close (lua);
    return;
  }
  //数据库地址
  lua_getglobal (lua,"db_host");
  db_host = lua_tostring (lua, -1);

  //数据库用户名
  lua_getglobal (lua,"db_username");
  db_username = lua_tostring (lua, -1);

  //数据库密码
  lua_getglobal (lua,"db_password");
  db_password = lua_tostring (lua, -1);

  //数据库名
  lua_getglobal (lua,"db_database");
  db_database = lua_tostring (lua, -1);

  //IP
  lua_getglobal (lua,"server_ip");
  server_ip = lua_tostring (lua, -1);

  //username
  lua_getglobal (lua, "username");
  username = lua_tostring(lua, -1);

  //passwd
  lua_getglobal (lua, "password");
  passwd = lua_tostring(lua, -1);

  //端口
  lua_getglobal (lua,"server_port");
  server_port = lua_tointeger (lua, -1);

  //学校iｄ
  lua_getglobal (lua,"school_id");
  school_id = lua_tointeger (lua, -1);

  //游戏数量
  lua_getglobal (lua,"game_count");
  game_count = lua_tointeger (lua, -1);

  lua_pop (lua,8);

  lua_close (lua);
  return;
}
