
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use default constructor of classes.
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     X, Y;
public:
    void    setPosition (int, int);
    int     getX (void);
    int     getY (void);
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

int
main (void)
{
    d2Vector    v1, v2;
    v1.setPosition (1, 2);
    v2.setPosition (3, 4);
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;

    return (0);
}
