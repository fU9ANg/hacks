#include <stdio.h>
#include <stdlib.h>

void
itob (unsigned long n, char *s, unsigned long b)
{
    char   c;
    static i=0;

    if(b<2) return;         /* error */

    if(n/b)
        itob(n/b, s, b);    /* Recursion */

    if(n%b>9)
        c=n%b+'7';
    else
        c=n%b+'0';

    (i++)[s]=c;
}

main(int argc, char** argv)
{
    if (argc<2) {
        printf ("Usage: %s `number' `base'.\n", argv[0]);
        exit (1);
    }

    char s[64];
    itob (atoi (*(argv+1)), s, atoi (*(argv+2)));
    printf ("%s\n", s);
}
