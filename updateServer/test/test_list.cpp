

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main ()
{
    list<int> l;
    map<int, int> m;

    int iArray[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int i;

    for (i=0; i<10; i++)
    {
        m.insert (pair<int, int> (i, iArray[i]));
        l.push_back (iArray[i]);
    }

    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }

    for (it = l.begin(); it != l.end();) 
    {
        if (*it == 5)
            l.erase (it++);
        else
            it++;
    }

    while (!l.empty())
    {
        cout << l.front() << endl;
        l.pop_front();
    }

    return (0);
}
