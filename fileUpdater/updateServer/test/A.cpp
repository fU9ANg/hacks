
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class A
{
    public:
        A () {
            i = 100;
            j = 'A';
            k = 10.5f;
        }

        operator int() {
            return (i);
        }

        operator char() {
            return (j);
        }

        operator float() {
            return (k);
        }

    private:
        int     i;
        char    j;
        float   k;
};

int main ()
{
    A a;
    int i;
    char j;
    float k;

    i = a;
    j = a;
    k = a;

    cout << "i=" << i << ", j=" << j << ", k=" << k << endl;

    return (0);
}
