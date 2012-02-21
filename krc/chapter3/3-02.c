#include <stdio.h>
#include <stdlib.h>

_escape (char s[], char t[])
{
    int i=0, j=0;
    while (s[i]) {
        switch (s[i]) {
            case '\n':
                t[j++]='\\';
                t[j++]='n';
                break;
            case '\t':
                t[j++]='\\';
                t[j++]='t';
                break;
            default:
                t[j++]=s[i];
        }
        i++;
    }
    t[j]='\0';
}

escape (char s[], char t[])
{
    int i=0, j=0, flag=0;

    while (s[i]) {
        if ((s[i])=='\\')
            flag=1;
        else {
            if (flag) {
                switch (s[i]) {
                    case 'n':
                        t[j++]='\n';
                        break;
                    case 't':
                        t[j++]='\t';
                        break;
                    default:
                        ;
                }
                flag=0;
            } else
                t[j++]=s[i];
        }
        i++;
    }
    t[j]='\0';
}

main(int argc, char **argv)
{
    char t[128], s[128];
    if (argc < 2) {
        printf ("Usage: %s `string'.\n", *argv);
        exit (1);
    }

    escape (*++argv, t);
    printf ("%s\n", t);
    _escape (t, s);
    printf ("%s\n", s);
}
