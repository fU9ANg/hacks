/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: key_comp and value_comp of set
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main ()
{
    string str[] = {"oH", "Hi", "The Doom", "and Quake", "of ID"};
    set<string>::iterator it;
    //set<string>::key_compare comp;
    set<string>::value_compare comp;
    set<string> s (str, str+5);
    comp = s.key_comp ();
    
    it = s.begin ();
    for (; comp (*it, "of ID"); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return (0);
}
