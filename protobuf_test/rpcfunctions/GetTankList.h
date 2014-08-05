
#ifndef _GETTANKLIST_H
#define _GETTANKLIST_H

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include "RpcFunctionBase.h"

using namespace std;
namespace RpcFunctions {
    class GetTankList : public RpcFunctionBase
    {
    public:
        void Invoke (int playerid);
        bool SendResult (void);
    };
};

#endif  //_GETTANKLIST_H
