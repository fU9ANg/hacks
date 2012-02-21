
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Macro definitions and how to use it.
 */

#include <iostream>

using namespace std;

#define MAX(x, y)   ((x) > (y) ? (x) : (y))
#define COUT(x, y)  x##y
#define OUTPUT(x)   COUT(c,out) << #x " = " << x << endl

int main (void)
{
    int     x = 5, y;
    y = MAX (x, 2);
    OUTPUT (y);
    OUTPUT (MAX (7, x));

    #undef MAX
    #undef COUT
    #undef OUTPUT

    return (0);
}
