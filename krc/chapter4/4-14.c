#include <stdio.h>

#define SWAP(t, x, y) {t tmp; tmp=x; x=y; y=tmp;}

main(int argc, char **argv)
{
    int  x=-2147483647;
    int  y= 2147483647;
    SWAP (int, x, y);

    printf ("x=%d, y=%d\n", x, y);
}
