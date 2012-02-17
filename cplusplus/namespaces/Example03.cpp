
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use keyword 'using'
 */

#include <iostream>

using namespace std;

namespace module1
{
    int     iX = 10000;
}

namespace module2
{
    double  dPi = 3.141;
}

int
main (void)
{
    using namespace module1;
    cout << "module1 :: iX  = " << iX  << endl;
    cout << "module2 :: dPi = " << module2 :: dPi << endl;

    return (0);
}
