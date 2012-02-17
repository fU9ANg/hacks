
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
        throw 10;
        cout << "go to here" << endl;
        try
        {
            throw 20;
        }
        catch (int e)
        {
            throw e+10;
        }
    }
    catch (int e)
    {
        cout << "An exception occurred." << e  << endl;
    }

    return (0);
}
