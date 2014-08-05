
#include "Login.h"


void RpcFunctions::Login::Invoke (int clientid, int clienttype, string username, string password)
{
    // TODO:
    cout << "clientid = " << clientid;
    cout << "clienttype = " << clienttype;
    cout << "username = " << username;
    cout << "password = " << password;

    returnResult ("abc", "def");
}

