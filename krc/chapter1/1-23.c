#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    S1=1,
    S2=2,
    S3=3,
    S4=4
} se;
/*
 *                       !*   !'/'
 *                       +-+------+
 *           '/'     '*' v | '*'  |
 * --> ((1)) --> (2) --> (3) --> (4) --+
 *     ^   |      |                    |
 *     |___|______|____________________|
 *      !'/' !'*'          '/'
 *       
 */
void f23()
{
    char c;
    se = S1;
    while ((c=getchar()) != EOF) {
        if (se==S1) {           /* State 1 */
            if (c=='/') se=S2;
        }
        else if (se==S2) {      /* State 2 */
            if (c=='*') se=S3;
            else {
                putchar ('/');
                se=S1;
            }
        }
        else if (se==S3) {      /* State 3 */
            if (c=='*') se=S4;
        }
        else if (se==S4) {      /* State 4 */
            if (c=='/') {
                se=S1;
                continue;
            }
            else 
                se=S3;
        }
        else                    /* error * / */
            puts ("The state machine is error.\n");

        /*
         * Print an character to STDOUT, 
         * only in the `State 1' of machine.
         */
        if (se==S1)
            putchar (c);
    }
}

int main()
{
    f23();
}
