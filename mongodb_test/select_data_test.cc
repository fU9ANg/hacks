
#include <iostream>
#include "client/dbclient.h"

using namespace mongo;
using namespace std;

int main (int argc, char** argv)
{
    DBClientConnection conn;
    BSONObj obj;
    BSONObj obj1;
    BSONObj temp_obj;

    // set values of DB object
    obj = BSONObjBuilder().append ("name", "fU9ANg").append ("e-mail", "bb.newlife@gmail.com").obj();

    temp_obj = BSONObjBuilder().obj();

    try {
        conn.connect ("localhost:11011");
        printf ("connected...\n");
    }
    catch (DBException& dbe) {
        printf ("exception: %s\n", dbe.what ());
        exit (EXIT_FAILURE);
    }

    printf ("select bson object to mongodb\012");
    // then, select data to mongodb
    obj1 = conn.findOne ("unix.programmer", obj, &temp_obj);

    // printf obj1
    // TODO:

    exit (EXIT_SUCCESS);
}
