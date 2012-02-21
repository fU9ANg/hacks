#include <stdlib.h>
#include <stdio.h>

int htoi (char *s)
{
    if (!s)
        return (-1);
    char*p=s;
    int  r=0;

    if ((*s=='0') && ((*(s+1)=='x') || (*(s+1)=='X')))
        p=s+2;

#if 1
    while (*p) {
        if ((*p>='0') && (*p<='9'))
            r=r*16+(*p-'0');
        else if ((*p>='A') && (*p<='F'))
            r=r*16+(*p-'A'+10);
        else if ((*p>='a') && (*p<='f'))
            r=r*16+(*p-'a'+10);
        else
            r=-1;

        p++;
    }

    return (r?r:-1);
#endif

}


int main(int argc, char **argv)
{
    if (argc < 2) {
        printf ("Usage: %s `hex-string'\n", *argv);
        exit (1);
    }

    printf ("%d\n", htoi (*++argv));

    return (0);
}
