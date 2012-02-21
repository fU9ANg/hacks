#include <stdio.h>

void itoa (int n, char s[])
{
    int i=0;
    (n<0) ? (s[0]='-') : 1;

    /* FIXME */
    if ((n/10<0)?-(n/10):(n/10))
        itoa (((n/10<0)?-(n/10):(n/10)), s);
    while (s[i]) i++;
    s[i++] =((n%10<0)?(-(n%10)):(n%10))+'0';
    s[i]   ='\0';
}

main(int argc, char **argv)
{
    char s[64];

    if (argc < 2) {
        printf ("Usage: %s `number'.\n", *argv);
        return (1);
    }
    s[0]='\0';
    itoa (atoi (*(argv+1)), s);
    printf ("%s\n", s);
}
