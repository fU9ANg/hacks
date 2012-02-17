
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use constructors and destructors.
 */

#include <iostream>

using namespace std;

class d2Vector
{
protected:
    int     X, Y;
public:
    d2Vector ()
    { cout << "d2Vector:\tno parameters in the constractor\n"; }
    d2Vector (int i)
    { cout << "d2Vector:\tint parameters in the constractor\n"; }
    ~d2Vector ()
    { cout << "d2Vector:\tin the destractor\n"; }
};


class d2VectorAdd : public d2Vector
{
public:
    d2VectorAdd (int i)
    { cout << "d2VectorAdd:\tint parameters in the constractor\n"; }
    ~d2VectorAdd ()
    { cout << "d2VectorAdd:\tin the destractor\n"; }
};

class d2VectorSub : public d2Vector
{
public:
    d2VectorSub (int i) : d2Vector (i)
    { cout << "d2VectorSub:\tint parameters in the constractor\n"; }
    ~d2VectorSub ()
    { cout << "d2VectorSub:\tin the destractor\n"; }
};

/*
 * // nothing specified, so call default
 * d2VectorAdd (int i)
 * // equivalent to follow:
 * d2VectorAdd (int i) : d2Vector ()
 *
 * // constractor specified, so call this
 * d2VectorSub (int i) : d2Vector (i)
 */
int
main (void)
{
    d2VectorAdd     v1 (1);
    d2VectorSub     v2 (2);
    cout << "-------" << endl;
    return (0);
}
