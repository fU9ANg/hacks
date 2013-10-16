

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
    map<int, int> m;

    int iArray[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int i;

    for (i=0; i<10; i++)
    {
        m.insert (pair<int, int> (i, iArray[i]));
    }

    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << "first = " << it->first
             << "second = " << it->second << endl;
    }

    for (it = m.begin(); it != m.end(); it)
    {
        cout << "first = " << it->first
             << ", second = " << it->second << endl;
        m.erase (it++);
    }

    if (m.empty())
        cout << "size=" << m.size() << endl;
    return (0);
}
