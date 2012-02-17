
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use multiple inheritance.
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

class d2Print
{
public:
    void    print (int x, int y) { cout << " X = " << x
                                        << " Y = " << y
                                        << endl;
                                 }
};

class d2VectorAdd : public d2Vector, public d2Print
{
public:
    void    operate (int i)
    {
        X += i;
        Y += i;
    }
};

class d2VectorSub : public d2Vector, public d2Print
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
    v1.setPosition (1, 2);
    v2.setPosition (3, 4);
    v1.operate (1);
    v2.operate (1);
    v1.print (v1.getX(), v1.getY());
    v2.print (v2.getX(), v2.getY());

    return (0);
}
