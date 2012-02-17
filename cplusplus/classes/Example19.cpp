
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: virtual members can be called
 *          from the abstract base class.
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
    void    outputPoint (void)
    {
        this->operate (1);
        cout << "(x, y) = " << X << ", "
                            << Y
                            << endl; 
    }
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
    p1->outputPoint ();
    p2->outputPoint ();

    return (0);
}
