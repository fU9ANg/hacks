
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use predefined macro names, such as:
 *          __LINE__, __FILE__, __DATE__, __TIME__
 */

#include <iostream>

using namespace std;

int main (void)
{
    cout << "This is the line number: " << __LINE__
         << " of file: " << __FILE__ << endl
         << "It's compilation began: " << __DATE__
         << " at " << __TIME__ << endl
         << "The compiler gives a __cplusplus value of: " << __cplusplus << endl;

    return (0);
}
