
#ifndef __RPCFUNCTIONBASE_H_
#define __RPCFUNCTIONBASE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef std::string                 rpc_value_t;
typedef std::vector<rpc_value_t>    rpc_arg_list_t;

class RpcFunctionBase
{
public:
    bool hasResult (void);
    bool SendResult (void);

    const rpc_arg_list_t& getReturnValues ()  const;
    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                       const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                       const rpc_value_t& v7, const rpc_value_t& v8, const rpc_value_t& v9, \
                       const rpc_value_t& v10);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                       const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                       const rpc_value_t& v7, const rpc_value_t& v8, const rpc_value_t& v9);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                       const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                       const rpc_value_t& v7, const rpc_value_t& v8);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                       const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                       const rpc_value_t& v7);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                       const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                       const rpc_value_t& v4, const rpc_value_t& v5);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                       const rpc_value_t& v4);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3);

    void returnResult (const rpc_value_t& v1, const rpc_value_t& v2);

    void returnResult (const rpc_value_t& v1);

protected:
    rpc_arg_list_t retVals;
};

#endif //_RPCFUNCTIONBASE_H_
