
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: swap of vector
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (void)
{
    string str[] = {"The Doom", "and Quake", "of ID"};
    string str2[] = {"The SC", ", WOW", "and Diablo", "of Blizzard"};
    vector<string>::iterator it;
    vector<string> v (str+0, str+3);
    vector<string> v2 (str2, str2+4);

    cout << "vector1 is:" << endl;
    for (it = v.begin (); it != v.end (); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "vector2 is:" << endl;
    for (it = v2.begin (); it != v2.end (); ++it)
        cout << *it << " ";
    cout << endl;


    v.swap (v2);
    cout << " ---After of swap--- " << endl;

    cout << "vector1 is:" << endl;
    for (it = v.begin (); it != v.end (); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "vector2 is:" << endl;
    for (it = v2.begin (); it != v2.end (); ++it)
        cout << *it << " ";
    cout << endl;

    return (0);
}
