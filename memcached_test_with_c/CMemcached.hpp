
#ifndef __MEMCACHED_COMMON
#define __MEMCACHED_COMMON

#include <libmemcached/memcached.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <time.h>

#define MC_SERVER   "172.16.10.103"
#define MC_PORT      11211

using namespace std;

class CMemcached
{
    public:
        ~CMemcached ()
        {
            memcached_free (memc);
        }

        CMemcached ()
        {
            memcached_return rc;
            memcached_server_st* server = NULL;

            memc    = memcached_create (NULL);
            server  = memcached_server_list_append (server, MC_SERVER, MC_PORT, &rc);
            rc      = memcached_server_push (memc, server);

            if (rc != MEMCACHED_SUCCESS)
                cout << "memcached_server_push failed! rc: " << rc << endl;
        };

        int insert (const char* key, const char* value, time_t expiration = 5)
        {
            if (key == NULL || value == NULL)
                return (-1);

            uint32_t flags = 0;

            memcached_return rc;
            rc = memcached_set (memc, key, strlen (key), value, strlen (value), expiration, flags);

            // insert success
            if (rc == MEMCACHED_SUCCESS)
                return (1);
            else
                return (0);
        }

        string select (const char* key)
        {
            if (NULL == key)
                return "";

            uint32_t flags = 0;
            memcached_return rc;

            size_t value_length;
            char* value = memcached_get (memc, key, strlen (key), &value_length, &flags, &rc);

            // select success
            if (rc == MEMCACHED_SUCCESS)
                return (value);

            return ("");
        }

    private:
        memcached_st* memc;
};
#endif
