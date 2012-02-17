
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use static members in the classes.
 */

#include <iostream>

using namespace std;

class d2Vector
{
// default - private:
    static  int privateN;
public:
    static  int publicN;

    // only cat static function operator static data
    static  int getPrivateN (void);
    d2Vector (void) { publicN++; privateN++; };
    ~d2Vector (void) { publicN--; privateN--; };
};

int
d2Vector :: getPrivateN (void)
{
    return (privateN);
}

// Notice: must initialize static variable outside
int d2Vector :: privateN = 0;
int d2Vector :: publicN  = 0;

int
main (void)
{

    d2Vector    v1, v2;

    cout << "d2Vector :: publicN = "
         << d2Vector :: publicN << endl;
    cout << "d2Vector :: privateN = "
         << d2Vector :: getPrivateN() << endl;

    d2Vector   *v3 = new d2Vector;

    cout << "d2Vector :: publicN = "
         << d2Vector :: publicN << endl;
    cout << "d2Vector :: privateN = "
         << d2Vector :: getPrivateN() << endl;

    delete v3;
    d2Vector   *v4 = new d2Vector[3];

    cout << "d2Vector :: publicN = "
         << d2Vector :: publicN << endl;
    cout << "d2Vector :: privateN = "
         << d2Vector :: getPrivateN() << endl;

    delete [] v4;

    cout << "d2Vector :: publicN = "
         << d2Vector :: publicN << endl;
    cout << "d2Vector :: privateN = "
         << d2Vector :: getPrivateN() << endl;

    return (0);
}
