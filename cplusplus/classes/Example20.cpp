
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use dynamic allocation and polymorphism 
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
    d2Vector*       p1 = new d2VectorAdd;
    d2Vector*       p2 = new d2VectorSub;
    p1->setPosition (1, 2);
    p2->setPosition (3, 4);
    p1->outputPoint ();
    p2->outputPoint ();

    delete p1;
    delete p2;

    return (0);
}
