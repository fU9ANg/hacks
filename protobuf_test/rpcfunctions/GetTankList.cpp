
#include "GetTankList.h"

void RpcFunctions::GetTankList::Invoke (int playerid)
{
    // TODO:
    cout << "GetTankList::Invoke - playerid = " << playerid << endl;
}

bool RpcFunctions::GetTankList::SendResult (void)
{
    return (true);
}
