
#ifndef _RPC_LOGIN_
#define _RPC_LOGIN_

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include "RpcFunctionBase.h"

using namespace std;

namespace RpcFunctions {
    class Login : public RpcFunctionBase 
    {
        public:
            void Invoke (int clientid, int clienttype, string username, string password);
            bool SendResult (void)
            {
                retVals.pop_back ();
                int rlt;
                string message;
                (void) rlt;
                (void) message;
#if 0
                // packet
                pbLoginRet pbObj;
                pbObj.set_rlt (rlt);
                pbObj.set_message (message);

                Buf* p = packet (ST_LOGIN, pbObj);
                CHECK_P (p);

                this->OwnClient->send (p);
#endif
                return (true);
            }
    };

};

#endif  //_RPC_LOGIN_
