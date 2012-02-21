#include <stdio.h>

#define W_LEN   127

#ifdef _DFA

/*       
 *      C = {A-Z, a-z};
 *
 *                     C
 *               +-+-------------+
 *            C  v | !C          |
 *   --> (1) --> (2) --> ((3)) --+
 *       ^ |               |
 *       |_|_______________|
 *                !C
 */    

enum {
    S1=0,
    S2=1,
    S3=2
} state;

void f12 ()
{
    char c, i=0, w[W_LEN], *p;
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

        if (state == S2)
            w[i++]=c;
        if (state == S3) {
            w[i++]='\0';
            printf ("%s\n", w);
            i=0;
        }
    }
}

#endif

#ifdef _EXERCISE
void f12 ()
{
    char c, i=0, f=0, w[W_LEN], *p;

    while ((c=getchar()) != EOF) {
        if (isalpha (c)) {
            f=1;
            w[i++]=c;
        } else if (f==1) {
            w[i]='\0';
            p=&w[0];

            while (*p)
                putchar (*p++);
            putchar ('\n');

            f=i=0;
        }
    }
}
#endif

int main ()
{
    f12 ();
}
