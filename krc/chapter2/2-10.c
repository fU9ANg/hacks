/*
 *  Expression ? Expression                    : Expression
 *  ((c>='A')  ? Expression                    : c)
 *  ((c>='A')  ? ((c<='Z') ? (Expression) : c) : c)
 *  ((c>='A')  ? ((c<='Z') ? (c +'a'-'A') : c) : c)
 */

#include <stdio.h>
#include <stdlib.h>

int lower (int c)
{
    return ((c>='A')?((c<='Z')?(c+'a'-'A'):c):c);
}

main()
{
    char c;
    while ((c=getchar()) != EOF) {
        putchar (lower (c));
    }
}
