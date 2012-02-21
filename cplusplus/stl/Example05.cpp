
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: begin of vector
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (void)
{
    string str[] = {"The Doom", "and Quake", "of ID"};
    
    vector<string> v (str+0, str+3);
    vector<string>::iterator it = v.begin ();
    while (it != v.end ())
        cout << *it++ << " ";
    cout << endl;

    it = v.begin () + 1;
    cout << *(v.begin () + 1) << endl;

    return (0);
}
