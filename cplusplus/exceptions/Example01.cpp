
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: How to use it.
 */

#include <iostream>

using namespace std;

int
main (void)
{
    try
    {
        throw 20;
    }
    catch (int e)
    {
        cout << "An exception occurred." << e  << endl;
    }

    return (0);
}
