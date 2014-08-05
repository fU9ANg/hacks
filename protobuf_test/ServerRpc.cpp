
#include "message/proto/protocol.pb.h"
#include "ServerRpc.h"
#include "RpcManager.h"

#include "rpcfunctions/Login.h"
#include "rpcfunctions/GetTankList.h"

void RpcManager::InitFunctionMap()
{
    sHandlerMap[1] = &ServerRpc::Login_HANDLER;
    sHandlerMap[2] = &ServerRpc::GetTankList_HANDLER;
}

RpcFunctionBase* ServerRpc::GetTankList_HANDLER (char *data)
{
    string sData = data;

    ServerProtocol::pbGetTankListArg pbObj_;
    pbObj_.ParseFromString (sData);

    int playerid = pbObj_.playerid ();

    RpcFunctions::GetTankList* fnObj = new RpcFunctions::GetTankList ();
    if (fnObj) {
        fnObj->Invoke (playerid);
    }
    else {
        cout << "[DEBUG]: RpcFunctions::GetTankList - can't found Rpc" << endl;
        return (NULL);
    }

    return (fnObj);
}

RpcFunctionBase* ServerRpc::Login_HANDLER (char *data)
{
    string sData = data;

    ServerProtocol::pbLoginArg pbObj_;
    pbObj_.ParseFromString (sData);

    int clientid = pbObj_.clientid ();
    int clienttype = pbObj_.clienttype ();
    string username = pbObj_.username ();
    string password = pbObj_.password ();

    RpcFunctions::Login* fnObj = new RpcFunctions::Login ();
    if (fnObj) {
        fnObj->Invoke (clientid, clienttype, username, password);
    }
    else {
        cout << "[DEBUG]: RpcFunctions::Login - can't found Rpc" << endl;
        return (NULL);
    }

    return (fnObj);
}
