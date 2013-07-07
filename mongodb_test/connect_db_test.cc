
#include <iostream>
#include <string>
#include "client/dbclient.h"

using namespace mongo;
using namespace std;

int main (int argc, char** argv)
{
    DBClientConnection conn;
    string connect_str;
    string temp_str;

    if (argc != 3) {
        printf ("usage: %s <address> <port>\n", argv[0]);
        exit (EXIT_FAILURE);
    }

    try {
        connect_str = argv[1];
        temp_str = argv[2];
        connect_str = connect_str + ":" + temp_str;
        conn.connect (connect_str.c_str());

        printf ("connected!\n");
        exit (EXIT_SUCCESS);
    }
    catch (DBException& dbe) {
        printf ("except: %s\n", dbe.what ());
        exit (EXIT_FAILURE);
    }

    exit (EXIT_SUCCESS);
}
