
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use constructor for class 'd2Vector'.
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     X, Y;
public:
    d2Vector (int, int);
    int     getX (void);
    int     getY (void);
};

d2Vector :: d2Vector (int x, int y)
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

int
main (void)
{
    d2Vector    v1 (1, 2), v2 (3, 4);
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;

    return (0);
}
