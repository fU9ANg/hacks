

#include "RpcManager.h"
#include "ServerRpc.h"
#include "RpcFunctionBase.h"

RpcManager* RpcManager::pInstance = NULL;
RpcManager::rpc_handler_function_t RpcManager::sHandlerMap[];

RpcManager* RpcManager::Instance ()
{
    if (pInstance == NULL)
        pInstance = new RpcManager ();

    return (pInstance);
}

bool RpcManager::StartFunctionCall (char* buffer)
{
    if (!buffer)
        return (false);

    int index = *(int *) buffer;
    char* data = buffer + sizeof (int);

    cout << "function index = " << index << endl;
    rpc_handler_function_t& fn = sHandlerMap[index];
    if (fn) {
        RpcFunctionBase* pFnObj = fn (data);

        // RpcFunction Object ptr
        if (pFnObj) {
            if (pFnObj->hasResult ()) {
                pFnObj->SendResult ();
            }
        }
        else {
            cout << "[DEBUG]: RpcManager::StartFunctionCall - RpcFunctionBase == NULL" << endl;
            return (false);
        }
    }
    else {
        cout << "[DEBUG]: RpcManager::StartFunctionCall - can't find handler by functionid = " << index << endl;
        return (false);
    }


    return (true);
}

