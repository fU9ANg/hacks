
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use friend class.
 */

#include <iostream>

using namespace std;

// forword definition
class d2Vector;
class d2Vector3;


class d2Vector
{
    int     X, Y;
public:
    d2Vector (int x, int y) { X = x; Y = y; };
    friend  class d2Vector3;
};

class d2Vector3
{
    int     X, Y, Z;
public:
    void    convertFromVector2  (const d2Vector& v);
    void    print (void) { cout << " X = " << X
                                << " Y = " << Y
                                << " Z = " << Z
                                << endl;
                         };
};

void
d2Vector3 :: convertFromVector2 (const d2Vector& v)
{
    // Access private data fields of class 'd2Vector'
    X = v.X;
    Y = v.Y;
    Z = 0;
}

int
main (void)
{
    d2Vector    v1 (1, 2);
    d2Vector3   v2;
    v2.convertFromVector2 (v1);
    v2.print ();

    return (0);
}
