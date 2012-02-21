#include <stdio.h>

/*
 *  C= {'\n', '\\', '\t'}
 *
 *               +-----+
 *          C    v     | C
 * --> (1) --> ((2)) --+
 *     ^ |       |
 *     |_|_______|
 *         !C
 */

void f10 () 
{
    char c;
    while ((c=getchar()) != EOF) {
        if (c==0x08)      printf ("\\b");       /* \b */
        else if (c==0x09) printf ("\\t");       /* \t */
        else if (c==0x0a) printf ("\\n");       /* \n */
        else if (c==0x0d) printf ("\\r");       /* \r */
        else if (c==0x20) printf ("\\S");       /* space */
        else              putchar(c);           /* other */
    }
}

int main ()
{
    f10 ();
}
