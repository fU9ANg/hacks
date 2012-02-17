
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
    int i;
    try
    {
        i = 100;
        try
        {
            throw i;
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
