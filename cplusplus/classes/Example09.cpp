
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use the keyword 'this'
 */

#include <iostream>

using namespace std;

class d2Vector
{
    int     X, Y;
public:
    bool    isSelf (const d2Vector& v);
    bool    isSelf (const d2Vector* v);
};

bool
d2Vector :: isSelf (const d2Vector& v)
{
    if (&v == this)
        return (true);
    else
        return (false);
}

bool
d2Vector :: isSelf (const d2Vector* v)
{
    if (v == this)
        return (true);
    else
        return (false);
}

int
main (void)
{
    d2Vector    v1, v2;

    cout << "v1.isSelf (v1) = " 
         << (v1.isSelf (v1)  ? "Yes" : "No")
         << endl;
    cout << "v1.isSelf (v2) = "
         << (v1.isSelf (v2)  ? "Yes" : "No")
         << endl;
    cout << "v1.isSelf (&v1)= "
         << (v1.isSelf (&v1) ? "Yes" : "No")
         << endl;
    cout << "v1.isSelf (&v2)= "
         << (v1.isSelf (&v2) ? "Yes" : "No")
         << endl;

    return (0);
}
