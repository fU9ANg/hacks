
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Templates and how to understand it.
 */

#include <iostream>

using namespace std;

// definition a template to swap two type
template<typename type>
void swap (type* a, type* b)
{
    type    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main (void)
{
    float   di = 2.14,  dj = 3.15;
    int     ii = 1,     ij = 2;
    string  si = "good",sj = "bad";

    cout << "double di=" << di << ",\tdj=" << dj << endl;
    cout << "int    ii=" << ii << ",\tij=" << ij << endl;
    cout << "string si=" << si << ",\tsj=" << sj << endl;

    cout << "=======================\n";

    swap (di, dj);
    swap (ii, ij);
    swap (si, sj);

    cout << "double di=" << di << ",\tdj=" << dj << endl;
    cout << "int    ii=" << ii << ",\tij=" << ij << endl;
    cout << "string si=" << si << ",\tsj=" << sj << endl;

    return (0);
}
