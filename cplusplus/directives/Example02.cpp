
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: Conditional inclusions.
 */

#include <iostream>

using namespace std;

#ifndef BUFFERSIZE
#define BUFFERSIZE  10
#endif

#if BUFFERSIZE > 100
#undef BUFFERSIZE
#define BUFFERSIZE 100

#elif BUFFERSIZE < 10
#undef BUFFERSIZE
#define BUFFERSIZE 10

#else
#undef BUFFERSIZE
#define BUFFERSIZE 50
#endif

int main (void)
{
    char    s[BUFFERSIZE];

    cout << sizeof (s) << endl;
}
