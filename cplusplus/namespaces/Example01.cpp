
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Definition a namespace and how to use it.
 * The format of namespace is:
 *      namespace identifier
 *      {
 *          ...
 *      }
 */

#include <iostream>

using namespace std;

namespace module1
{
    int     iX = 10;
}

namespace module2
{
    double  dPi = 3.14;
}

int
main (void)
{
    cout << "module1 :: iX  = " << module1 :: iX  << endl;
    cout << "module2 :: dPi = " << module2 :: dPi << endl;

    return (0);
}
