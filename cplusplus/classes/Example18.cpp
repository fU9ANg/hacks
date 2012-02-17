
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use abstract base class.
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
    // definition a virtual base class
    virtual void  operate (int i) = 0;
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
    // d2Vector        v3;          // error
    d2Vector*       p1 = &v1;
    d2Vector*       p2 = &v2;
    // d2Vector*       p3 = &v3;    // error
    p1->setPosition (1, 2);
    p2->setPosition (3, 4);
    // p3->setPosition (5, 6);      // error
    v1.operate (1);
    v2.operate (2);
    // v3.operate (3);              // error
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;
    /* error
    cout << "v3.(x, y) = " << v3.getX () << ", "
                           << v3.getY ()
                           << endl;
    */

    return (0);
}
