
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: clear of vector
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

    cout << "Size of vector = " << v.size () << endl;
    cout << "Capacity of vector = " << v.capacity () << endl;
    v.resize (5);
    cout << "Size of vector = " << v.size () << endl;
    cout << "Capacity of vector = " << v.capacity () << endl;

    cout << "--- After of clear function ---" << endl;

    v.clear ();

    cout << "Size of vector = " << v.size () << endl;
    cout << "Capacity of vector = " << v.capacity () << endl;

    return (0);
}
