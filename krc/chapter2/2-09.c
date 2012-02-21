#include <stdio.h>
#include <stdlib.h>

int bitcount (unsigned x)
{
    int b;
    for (b=0; x!=0; x>>=1)
        if (x & 01)
            b++;
    return b;
}

int bitcount2 (unsigned x)
{
    int b;
    if  (x>0)        b=1;
    for (; x&=(x-1); b++) ;
    return b;
}

main(int argc, char **argv)
{
    if (argc < 2) {
        printf ("Usage: %s `number`.\n", *argv);
        exit (1);
    }
    printf ("%d, %d\n", bitcount (atoi (*(argv+1))), \
                        bitcount2 (atoi (*(argv+1))));
}
