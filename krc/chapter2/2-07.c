/*
=====================================
invert (x, 5, 3)
    x                        <-------
    +---+---+---+---+---+---+---+---+
    | 1 | 1 | 1 | 1 | 0 | 1 | 1 | 1 |
    +---+---+---+---+---+---+---+---+
                  ^       |
                  |-------+
                  |  n=3
                 p=5

                   \|/
                    v

    +---+---+---+---+---+---+---+---+
    | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 1 |
    +---+---+---+---+---+---+---+---+
=====================================
 */
#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n)
{
    /* FIXME */
    //return (x & ((~(~0 << (p+1-n)) | (~0 << (p+1))))) | \
        ((((x >> (p+1-n)) & ~(~0 << n)) ^ (~(~0 << n))) << (p+1-n));
    return (x & ((~(~0 << (p-n)) | (~0 << (p))))) | \
        ((((x >> (p-n)) & ~(~0 << n)) ^ (~(~0 << n))) << (p-n));
}
unsigned invert2(unsigned x, int p, int n)
{
    //return (x ^ ((~(~0 << n)) << (p+1-n)));
    return (x ^ ((~(~0 << n)) << (p-n)));
}

main()
{
    printf ("%d, %d\n", invert2(247, 5, 3), invert(235, 5, 3));
    printf ("%d, %d\n", invert2(235, 5, 3), invert(247, 5, 3));
}
