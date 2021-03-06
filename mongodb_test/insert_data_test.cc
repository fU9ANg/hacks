
#include <iostream>
#include "client/dbclient.h"

using namespace mongo;
using namespace std;

int main (int argc, char** argv)
{
    DBClientConnection conn;
    BSONObj obj;

    // set values of DB object
    obj = BSONObjBuilder().append ("name", "fU9ANg").append ("e-mail", "bb.newlife@gmail.com").obj();

    try {
        conn.connect ("localhost:11011");
        printf ("connected...\n");
    }
    catch (DBException& dbe) {
        printf ("exception: %s\n", dbe.what ());
        exit (EXIT_FAILURE);
    }

    printf ("insert bson object to mongodb\012");
    // then, insert data to mongodb
    conn.insert ("unix.programmer", obj);

    // insert second Bson object to mongodb
    obj = BSONObjBuilder().append ("name", "f0rsaken").append ("e-mail", "backbone.jym@xxx.com").obj();
    //BSONObjBuilder().append ("name", "f0rsaken");
    //BSONObjBuilder().append ("e-mail", "backbone.jym@xxx.com");
    //obj = BSONObjBuilder().obj();
    conn.insert ("unix.programmer", obj);

    exit (EXIT_SUCCESS);
}
