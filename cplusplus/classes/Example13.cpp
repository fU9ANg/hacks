
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: derived classes.
 *
 * The format is:
 *      class derived_class_name : public base_class_name
 */

#include <iostream>

using namespace std;

class d2Vector
{
protected:
    int     X, Y;
public:
    void    setPosition (int x, int y)
    {
        X = x;
        Y = y;
    }
    int     getX (void) { return (X); }
    int     getY (void) { return (Y); }
};

/*
 * inherited way:
 * ----------------------------------------------------------------------
 *                             private
 * private, protected, public  ------> no inherited, private, private
 *
 *                             protected
 * private, protected, public  ------> no inherited, protected, protected
 *
 *                             public
 * private, protected, public  ------> no inherited, protected, public
 * ----------------------------------------------------------------------
 */

class d2VectorAdd : public d2Vector
{
public:
    int operate (int x, int y)
    {
        X += x;
        Y += y;
        return (0);
    }
};

class d2VectorSub : public d2Vector
{
public:
    int operate (int x, int y)
    {
        X -= x;
        Y -= y;
        return (0);
    }
};

int
main (void)
{
    d2VectorAdd     v1;
    d2VectorSub     v2;
    v1.setPosition (1, 2);
    v2.setPosition (3, 4);
    v1.operate (1, 1);
    v2.operate (1, 1);
    cout << "v1.(x, y) = " << v1.getX () << ", "
                           << v1.getY ()
                           << endl;
    cout << "v2.(x, y) = " << v2.getX () << ", "
                           << v2.getY ()
                           << endl;

    return (0);
}
