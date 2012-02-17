
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use overloading operators.
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     X, Y;
public:
    d2Vector (void);
    d2Vector (int, int);
    d2Vector  operator + (const d2Vector& v);
    d2Vector  operator - (const d2Vector& v);
    d2Vector& operator = (const d2Vector& v);
    int     getX (void);
    int     getY (void);
};

d2Vector :: d2Vector (void)
{
}

d2Vector :: d2Vector (int x, int y)
{
    X = x;
    Y = y;
}

d2Vector
d2Vector :: operator + (const d2Vector& v)
{
    return (d2Vector (X + v.X, \
                      Y + v.Y));
}

d2Vector
d2Vector :: operator - (const d2Vector& v)
{
    return (d2Vector (X - v.X, \
                      Y - v.Y));
}

d2Vector&
d2Vector :: operator = (const d2Vector& v)
{
    X = v.X;
    Y = v.Y;
    return (*this);
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
    d2Vector    v1 (1, 2), v2 (3, 4);
    d2Vector    v3 = v2 + v1;
    d2Vector    v4 = v2.operator- (v1);
    d2Vector    v5 = v4;

    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;
    cout << "v3.(x, y) = " << v3.getX () << ", "
                           << v3.getY ()
                           << endl;
    cout << "v4.(x, y) = " << v4.getX () << ", "
                           << v4.getY ()
                           << endl;
    cout << "v5.(x, y) = " << v5.getX () << ", "
                           << v5.getY ()
                           << endl;

    return (0);
}
