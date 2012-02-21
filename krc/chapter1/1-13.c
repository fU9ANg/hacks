#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define W_LEN    32
/*       
 *   C = {A-Z, a-z};
 *
 *                     C
 *             +-+-------------+
 *          C  v | !C          |
 * --> (1) --> (2) --> ((3)) --+
 *     ^ |               |
 *     |_|_______________|
 *              !C
 */    

void f13 ()
{
    int w[W_LEN], n=0;
    char c;
    memset (w, 0, sizeof (w));

    while ((c=getchar()) != EOF) {
        if (isalpha (c)) n++;
        else {
            if (n) w[n]++;
            n=0;
        }
    }

    /* output */
    n=1;
    while (n<W_LEN) {
        if (w[n])
            printf ("word len=%d: count=%d\n", n, w[n]);
        n++;
    }
}

int main ()
{
    f13();
}
