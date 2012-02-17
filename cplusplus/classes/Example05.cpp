
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use copy constructors.
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     X, Y;
public:
    d2Vector (void);
    d2Vector (const d2Vector& v);
    int     getX (void);
    int     getY (void);
};

d2Vector :: d2Vector (void)
{
    X = Y = 1;
}

d2Vector :: d2Vector (const d2Vector& v)
{
    X = v.X;
    Y = v.Y;
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

int
main (void)
{
    d2Vector    v1;
    // d2Vector    v1(); -- error
    d2Vector    v2 (v1);
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;

    return (0);
}
