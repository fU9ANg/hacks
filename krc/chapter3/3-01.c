#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
             high = mid - 1;
        else
             low = mid + 1;
    }
#if 1
    if (low==n) {
        if (x==v[n-1])
            return (n-1);
        else
            return (-1);
    }
    else if (low) {     /* found match */
        return (low-1);
    }
    else
        return (-1);    /* no match */
#endif
}

main(int argc, char **argv)
{
    if (argc < 2) {
        printf ("Usage: %s `number'.\n", *argv);
        exit (1);
    }

    int i=0, v[100], x=0;
    while (i<100)
        v[i++]=i+100;

    printf ("locate=%d\n", binsearch (atoi (*++argv), &v[0], 100));
}
