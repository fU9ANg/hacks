
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use pointer to classes.
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

/*
 * summary:
 * +------------------------------------------+
 * | *v     | pointed by v                    |
 * | &v     | address of v                    |
 * | v.x    | member x of object v            |
 * | v->x   | member x of object pointed by v |
 * | (*v).x | equivalent to the previous one  |
 * | v[0]   | first object pointed by v       |
 * | v[n]   | (n+1)th object pointed by v     |
 * +------------------------------------------+
 */
int
main (void)
{
    d2Vector    v1, *v2, *v3, *v4;
    d2Vector    *v = new d2Vector[2];
    v2 = new d2Vector;
    v3 = &v1;
    v4 = new d2Vector;

    v1.setPosition (1, 2);
    v2->setPosition (3, 4);
    v4->setPosition (5, 6);
    v->setPosition (7, 8);
    v[1].setPosition (9,0);

    cout << "v1.(x, y)  = " << v1.getX () << ", "
                            << v1.getY ()
                            << endl;
    cout << "v2.(x, y)  = " << v2->getX () << ", "
                            << v2->getY ()
                            << endl;
    cout << "v3.(x, y)  = " << v3->getX () << ", "
                            << v3->getY ()
                            << endl;
    cout << "v4.(x, y)  = " << (*v4).getX () << ", "
                            << (*v4).getY ()
                            << endl;
    cout << "v[0].(x, y)= " << v[0].getX () << ", "
                            << v->getY ()
                            << endl;
    cout << "v[1].(x, y)= " << (&v[1])->getX () << ", "
                            << v[1].getY ()
                            << endl;

    return (0);
}
