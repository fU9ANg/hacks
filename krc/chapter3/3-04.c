#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 64

strlen (char s[])
{
    int i=0;
    while (s[i++]); return (i-1);
}

reverse (char s[])
{
    int i, j;
    char c;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

#if 0
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
         n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
         s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
#endif

#if 1
/* Modify it */
void itoa2(int n, char s[])
{
    int i, sign=0;

    if (n < 0)
        sign=1;
    i = 0;
    do {       /* generate digits in reverse order */
         s[i++] = (n%10<0)?(-(n%10)+'0'):(n%10+'0'); /* get next digit */
    } while (((n/10<0)?(-(n/=10)):(n/=10)) > 0);     /* delete it */

    if (sign)
         s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
#endif

main(int argc, char **argv)
{
    if (argc < 2) {
        printf ("Usage: %s `number'.\n", argv[0]);
        exit (1);
    }

    char s[MAXLEN];
    itoa2 (atoi (*++argv), s);
    printf ("%s\n", s);   
}
