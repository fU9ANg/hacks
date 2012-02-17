
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
    int     i;
    char    c;
    float   f;
    try
    {
        i = 100;
        c = 'A';
        f = 1.0f;
        try
        {
            throw c;
            // throw i; -- or
            // throw f; -- or
        }
        catch (int e)
        {
            throw e+10;
        }
        catch (char c)
        {
            throw c+1;
        }
        catch (float f)
        {
            throw f+1.0f;
        }
    }
    catch (int e)
    {
        cout << "An exception occurred." << e  << endl;
    }
    catch (char c)
    {
        cout << "An exception occurred." << c  << endl;
    }
    catch (float f)
    {
        cout << "An exception occurred." << f  << endl;
    }

    return (0);
}
