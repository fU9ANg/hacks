
#ifndef _RPCFUNCTIONBASE_H_
#define _RPCFUNCTIONBASE_H_

#include <iostream>
#include "RpcFunctionBase.h"

using namespace std;

class ServerRpc
{
public:
    static RpcFunctionBase* GetTankList_HANDLER (char *data);
    static RpcFunctionBase* Login_HANDLER (char *data);
};

#endif // _RPCFUNCTIONBASE_H_
