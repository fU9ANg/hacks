
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use pointers to base class.
 */

#include <iostream>

using namespace std;

class d2Vector
{
protected:
    int     X, Y;
public:
    void    setPosition (int x, int y)  { X = x; Y = y; }
    int     getX (void) { return (X); }
    int     getY (void) { return (Y); }
};

class d2VectorAdd : public d2Vector
{
public:
    void    operate (int i)
    {
        X += i;
        Y += i;
    }
};

class d2VectorSub : public d2Vector
{
public:
    void    operate (int i)
    {
        X -= i;
        Y -= i;
    }
};

int
main (void)
{
    d2VectorAdd     v1;
    d2VectorSub     v2;
    d2Vector*       p1 = &v1;
    d2Vector*       p2 = &v2;
    p1->setPosition (1, 2);
    p2->setPosition (3, 4);
    v1.operate (1);
    v2.operate (2);
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;

    return (0);
}
