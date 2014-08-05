

#ifndef _RPC_MANAGER_H
#define _RPC_MANAGER_H

#include <iostream>
#include <iomanip>
#include <tr1/memory>
#include <tr1/functional>
#include <string>

#include "RpcFunctionBase.h"

using namespace std;

class RpcManager
{
public:

    typedef std::tr1::function<RpcFunctionBase* (char* data)> rpc_handler_function_t;
    //typedef RpcFunctionBase* (*rpc_handler_function_t) (char* data);

    static RpcManager* Instance ();
    static bool StartFunctionCall (char* buffer);
    static void InitFunctionMap();

    static rpc_handler_function_t sHandlerMap[500];
private:
    static RpcManager *pInstance;

};

#define RPCMANAGER  RpcManager::Instance()

#endif  //_RPC_MANAGER_H
