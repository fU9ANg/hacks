#include <stdio.h>
#include <stdlib.h>

unsigned int rightrot (unsigned int x, unsigned int n)
{
    unsigned int r=x;
    unsigned int m= n%32;
    r= ((r >> m) | (r << (32-m)));

    return (r);
}

int
main()
{
    printf ("%d\n", rightrot (101, 34));
}
