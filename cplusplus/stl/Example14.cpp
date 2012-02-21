
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: insert of vector
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

    it = v.begin ();
    v.insert (it, "-");
    it = v.begin ();

    while (it != v.end ())
        cout << *it++ << " ";
    cout << endl;

    return (0);
}
