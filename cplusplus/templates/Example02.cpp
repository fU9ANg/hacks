
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Use the keyword 'cast'.
 */

#include <iostream>

using namespace std;

// definition a template to swap two type
template<class type>
type d2Max (type a, type b)
{
    type t;
    t = (a > b) ? a : b;
    return (t);
}

int main (void)
{
    int     i = 54, j = 56;
    long    l = 10, m = 50;

    cout << d2Max<int> (i, j) << endl;
    cout << d2Max<long> (l, m) << endl;

    return (0);
}
