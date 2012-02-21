#include <stdio.h>

#define LEN 3
/*
 * C= {'\n', sp, '\t'}
 *
 *               +-----+
 *          C    v     | C
 * --> (1) --> ((2)) --+
 *     ^ |       |
 *     |_|_______|
 *         !C
 */

void f08 ()
{
    int  a[LEN] = {0, 0, 0};
    char c;

    while ((c=getchar()) != EOF) {
        if (c==0x09) a[0]++;    /* HT \t */
        if (c==0x0A) a[1]++;    /* LF \n */
        if (c==0x20) a[2]++;    /* SPACE */
    }

    printf ("\\t=%d, \\n=%d, space=%d\n", a[0], a[1], a[2]);
}

int main ()
{
    f08();
}
