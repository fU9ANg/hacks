
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use keyword 'using namespace'
 */

#include <iostream>

using namespace std;

namespace module1
{
    int     iX = 1000;
}

namespace module2
{
    double  dPi = 3.14;
}

int
main (void)
{
    using namespace module1;
    using namespace module2;
    cout << "module1 :: iX  = " << iX  << endl;
    cout << "module2 :: dPi = " << dPi << endl;

    return (0);
}
