
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use friend functions of classes.
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     X, Y;
public:
    d2Vector (void) {};
    d2Vector (int x, int y) { X = x; Y = y; };
    void    setPosition (int, int);
    int     getX (void);
    int     getY (void);
    friend  d2Vector duplicate (const d2Vector&);
};

void
d2Vector :: setPosition (int x, int y)
{
    X = x;
    Y = y;
}

int
d2Vector :: getX (void)
{
    return (X);
}

int
d2Vector :: getY (void)
{
    return (Y);
}

d2Vector
duplicate (const d2Vector& v)
{
    // Access private data fields of class 'd2Vector'
    return (d2Vector (v.X * 2, \
                      v.Y * 2));
}

int
main (void)
{
    d2Vector    v1(1, 2), v2;
    v2 = duplicate (v1);
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;

    return (0);
}
