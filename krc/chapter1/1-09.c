#include <stdio.h>

#ifdef  _EXERCISE
void f09 ()
{
    char c, f=1;

    while ((c=getchar()) != EOF) {
        if (c==0x20) {
            if (f) {
                putchar (c);
                f=0;
            }
        } else {
            putchar (c);
            f=1;
        }
    }
}
#endif

#ifdef  _DFA
enum {
    s1=0,
    s2=1,
    s3=2
} state;

/*
                            +----+
            Space     Space v    | Space
   --> ((1)) --> ((2)) --> (3) --+
       ^   |       |        |
       |___|_______|________|
               !Space

 */
void f09 ()
{
    char c;
    state = s1;
    while ((c=getchar()) != EOF) {
        if (state == s1) {
            if (c==0x20)
                state = s2;
        }
        else if (state == s2) {
            if (c==0x20)
                state = s3;
            else
                state = s1;
        }
        else if (state == s3) {
            if (c!=0x20)
                state = s1;
        }

        /* print it */
        if ((state == s2) || (state == s1))
            putchar (c);
    }
}
#endif

int main ()
{
    f09 ();
}
