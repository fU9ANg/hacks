
#include <iostream>
#include "client/dbclient.h"

using namespace mongo;
using namespace std;

int main (int argc, char** argv)
{
    DBClientConnection conn;
    BSONObj obj;
    BSONObj obj1;

    // set values of DB object
    obj = BSONObjBuilder().append ("name", "fU9ANg").append ("e-mail", "bb.newlife@gmail.com").obj();
    obj1= BSONObjBuilder().append ("NAME", "fU9ANg").append ("E-MAIL", "bb.newlife@gmail.com").obj();

    try {
        conn.connect ("localhost:11011");
        printf ("connected...\n");
    }
    catch (DBException& dbe) {
        printf ("exception: %s\n", dbe.what ());
        exit (EXIT_FAILURE);
    }

    printf ("update bson object to mongodb\012");
    // then, update data to mongodb
    conn.update ("unix.programmer", obj, obj1);

    // update second Bson object to mongodb
    obj = BSONObjBuilder().append ("name", "f0rsaken").append ("e-mail", "backbone.jym@xxx.com").obj();
    obj1= BSONObjBuilder().append ("NAME", "f0rsaken").append ("E-mail", "backbone.jym@xxx.com").obj();
    //BSONObjBuilder().append ("name", "f0rsaken");
    //BSONObjBuilder().append ("e-mail", "backbone.jym@xxx.com");
    //obj = BSONObjBuilder().obj();
    conn.update ("unix.programmer", obj, obj1);

    exit (EXIT_SUCCESS);
}
