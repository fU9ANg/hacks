
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use keyword 'namespace'
 */

#include <iostream>

using namespace std;

namespace module1
{
    int     iX = 100000;
}

namespace module2
{
    double  dPi = 3.1415;
}

int
main (void)
{
    /* The format of namespace is:
     *      namespace new_name = old_name;
     */
    namespace LIST = module1;
    namespace MATH = module2;

    using namespace module1;
    cout << "module1 :: iX  = " << iX  << endl;
    cout << "module2 :: dPi = " << MATH :: dPi << endl;

    return (0);
}
