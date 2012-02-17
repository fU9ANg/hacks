
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use standard exceptions.
 */

#include <iostream>
#include <exception>    // include standard exception header file

using namespace std;

class d2Exception : public exception
{
    virtual const char* what () const throw ()
    {
        return "d2 exception happened";
    }

};

int main (void)
{
    d2Exception d2e;
    try
    {
        throw d2e;
    }
    catch (exception& e)
    {
        cout << e.what () << endl;
    }

    return (0);
}
