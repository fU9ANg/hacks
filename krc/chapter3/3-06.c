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

void itoa(int n, char s[], int m)
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
    while (i<m)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

main(int argc, char **argv)
{
    if (argc < 3) {
        printf ("Usage: %s `number' `width'.\n", argv[0]);
        exit (1);
    }

    char s[MAXLEN];
    itoa (atoi (*(argv+1)), s, atoi(*(argv+2)));
    printf ("%s\n", s);   
}
