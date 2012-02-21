#include <stdio.h>

#ifdef _EXERCISE

void f11 ()
{
    char c, w=0, f=0;
    while ((c=getchar()) != EOF) {
        if (isalpha (c))
            f=1;
        else
            if (f==1) {
                w++;
                f=0;
            }
    }
    printf ("count of word=%d\n", w);
}

#endif

#ifdef  _DFA

/*       
 *    C = {A-Z, a-z};
 *
 *                     C
 *             +-+-------------+
 *          C  v | !C          |
 * --> (1) --> (2) --> ((3)) --+
 *     ^ |               |
 *     |_|_______________|
 *              !C
 */    

enum {
    S1=0,
    S2=1,
    S3=2
} state;

void f11()
{
    char c;
    int  w=0;
    state = S1;
    while ((c=getchar()) != EOF) {
        if (state == S1) {
            if (isalpha (c))
                state = S2;
        }
        else if (state == S2) {
            if (!isalpha (c))
                state = S3;
        }
        else if (state == S3) {
            if (isalpha (c))
                state = S2;
            else
                state = S1;
        }

        if (state == S3)
            w++;
    }
    /* print it */
    printf ("words=%d\n", w?w:0);
}
#endif

int main ()
{
    f11 ();
}
