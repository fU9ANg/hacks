
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: pop_back of vector
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (void)
{
    string str[] = {"The Doom", "and Quake", "of ID"};
    vector<string>::iterator it;    
    vector<string> v (str+0, str+3);

    v.push_back (" ha ");
    v.push_back (" HAHA~ ");

    while (!v.empty ())
    {
        it = v.begin ();
        for (; it != v.end (); ++it)
            cout << *it;
        cout << endl;
        v.pop_back ();
    }

    return (0);
}
