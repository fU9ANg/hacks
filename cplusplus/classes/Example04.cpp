
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use overloading constructors.
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     X, Y;
public:
    d2Vector (void);
    d2Vector (int, int);
    int     getX (void);    // inline
    int     getY (void);    // inline
    int     XX (void);      // overload
    void    XX (int);       // overload
    int     YY (void);      // overload
    void    YY (int);       // overload
};

d2Vector :: d2Vector (void)
{
    X = Y = 1;
}

d2Vector :: d2Vector (int x, int y)
{
    X = x;
    Y = y;
}

inline int
d2Vector :: getX (void)
{
    return (X);
}

inline int
d2Vector :: getY (void)
{
    return (Y);
}

int
d2Vector :: XX (void)
{
    return (X);
}

void
d2Vector :: XX (int x)
{
    X = x;
}

int
d2Vector :: YY (void)
{
    return (Y);
}

void
d2Vector :: YY (int y)
{
    Y = y;
}

int
main (void)
{
    d2Vector    v1;
    // d2Vector    v1(); -- error
    d2Vector    v2 (3, 4);
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;

    return (0);
}
