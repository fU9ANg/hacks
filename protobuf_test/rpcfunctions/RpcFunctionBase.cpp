
#include <iostream>
#include "RpcFunctionBase.h"

bool RpcFunctionBase::hasResult (void)
{
    return (!retVals.empty ());
}

bool RpcFunctionBase::SendResult (void)
{
    return (false);
}

const rpc_arg_list_t& RpcFunctionBase::getReturnValues () const
{
    return (retVals);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                   const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                   const rpc_value_t& v7, const rpc_value_t& v8, const rpc_value_t& v9, \
                   const rpc_value_t& v10)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
    retVals.push_back (v4);
    retVals.push_back (v5);
    retVals.push_back (v6);
    retVals.push_back (v7);
    retVals.push_back (v8);
    retVals.push_back (v9);
    retVals.push_back (v10);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                   const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                   const rpc_value_t& v7, const rpc_value_t& v8, const rpc_value_t& v9)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
    retVals.push_back (v4);
    retVals.push_back (v5);
    retVals.push_back (v6);
    retVals.push_back (v7);
    retVals.push_back (v8);
    retVals.push_back (v9);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                   const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                   const rpc_value_t& v7, const rpc_value_t& v8)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
    retVals.push_back (v4);
    retVals.push_back (v5);
    retVals.push_back (v6);
    retVals.push_back (v7);
    retVals.push_back (v8);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                   const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6, \
                   const rpc_value_t& v7)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
    retVals.push_back (v4);
    retVals.push_back (v5);
    retVals.push_back (v6);
    retVals.push_back (v7);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                   const rpc_value_t& v4, const rpc_value_t& v5, const rpc_value_t& v6)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
    retVals.push_back (v4);
    retVals.push_back (v5);
    retVals.push_back (v6);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                   const rpc_value_t& v4, const rpc_value_t& v5)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
    retVals.push_back (v4);
    retVals.push_back (v5);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3, \
                   const rpc_value_t& v4)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
    retVals.push_back (v4);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2, const rpc_value_t& v3)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
    retVals.push_back (v3);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1, const rpc_value_t& v2)
{
    retVals.push_back (v1);
    retVals.push_back (v2);
}

void RpcFunctionBase::returnResult (const rpc_value_t& v1)
{
    retVals.push_back (v1);
}
