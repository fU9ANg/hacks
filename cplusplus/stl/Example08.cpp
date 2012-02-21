
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: resize of vector
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

    vector<string>::iterator it = v.begin ();
    while (it != v.end ())
        cout << *it++ << "-";
    cout << endl;

    cout << "front is: " << v.front () << endl;
    cout << "back is: " << v.back () << endl;

    return (0);
}
