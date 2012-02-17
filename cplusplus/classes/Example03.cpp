
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use the destructor of class. 
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     *X, *Y;
public:
    d2Vector (int, int);
    ~d2Vector(void);
    int     getX (void);
    int     getY (void);
};

d2Vector :: d2Vector (int x, int y)
{
    X = new int;
    Y = new int;
    *(this->X) = x;
    *(*this).Y = y;
}

d2Vector :: ~d2Vector (void)
{
    delete X;
    delete this->Y;
}

int
d2Vector :: getX (void)
{
    return (*X);
}

int
d2Vector :: getY (void)
{
    return (*(this->Y));
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
