
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Use the STL and how to understand it.
 *
 * Example: empty of vector
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (void)
{
    string str[] = {"The Doom", "and Quake", "of ID"};
    vector<string> v;
    
    cout << "Is empty? ";
    v.empty () ? cout << "Yes" : cout << "No";
    cout << endl;

    v.assign (str, str+3);

    cout << "After of Assign: " << endl;

    cout << "Is empty? ";
    v.empty () ? cout << "Yes" : cout << "No";
    cout << endl;

    return (0);
}
