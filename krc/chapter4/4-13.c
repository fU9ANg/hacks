#include <stdio.h>
#include <string.h>

reverse (char s[])
{
    char tmp, *p1=&s[0], *p2=&s[strlen(s)-1];
    
    void _reverse (char *p1, char *p2) {
        if (p1 < p2) {
            tmp=*p1;
            *p1=*p2;
            *p2=tmp;
            _reverse (++p1, --p2);
        }
    }

    _reverse (p1, p2);
}

main(int argc, char **argv)
{
    if (argc < 2) {
        printf ("Usage: %s `number'.\n", *argv);
        return (1);
    }

    printf ("%s\n", *(argv+1));
    reverse (*(argv+1));
    printf ("%s\n", *(argv+1));
}
