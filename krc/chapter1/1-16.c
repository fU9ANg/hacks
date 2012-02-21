#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 2

copy (char d[], char s[])
{
    int i=0;

    while (s[i] != '\0')
        d[i]=s[i++];
    d[i]='\0';
}

join (char d[], char s[])
{
    int i=0, l=strlen (d);

    while (s[i] != '\0')
        d[l++]=s[i++];
    d[l]='\0';
}

int
getline (char d[], int max)
{
    int  i;
    char c;

    for (i=0; (i<max-1) && ((c=getchar()) != EOF) && (c!='\n'); i++) /*******/
        d[i]=c;
    if (c=='\n')
        d[i++]=c;

    d[i]='\0';
    return (i);
}

main ()
{
    int  l=0, max=0;
    char line [MAXLEN];
    char tmp1 [MAXLEN], *tmp2=NULL, *tmp3=NULL, *tmp4=NULL;

    while ((l=getline (line, MAXLEN))>0) {
        if ((strrchr (line, '\n')) && (tmp2==NULL)) {
            if ((l>max) && (tmp3==NULL)) {
                max=l;
                copy (tmp1, line);
            }
        } else {
#if 1
            if (tmp2) {
                tmp4 = tmp2;
                tmp2 = (char*) malloc ((strlen (tmp4)+MAXLEN)*sizeof (char));
                copy (tmp2, tmp4);
                join (tmp2, line);
                free (tmp4);
                tmp4 = NULL;
            } else {
                tmp2 = (char *) malloc (MAXLEN*sizeof (char));
                copy (tmp2, line);
            }

            if (strrchr (line, '\n')) {
                if (strlen (tmp2) > max) {
                    max = strlen (tmp2);
                    if (tmp3 == NULL)
                        tmp3 = tmp2;
                    else {
                        tmp4 = tmp3;
                        tmp3 = tmp2;

                        free (tmp4);
                        tmp4 = NULL;
                    }
                } else
                    free (tmp2);

                tmp2 = NULL;
            }
#endif
        }
    }

    if (tmp2) {
        free (tmp2);
        tmp2 = NULL;
    }
    if (tmp4) {
        free (tmp4);
        tmp4 = NULL;
    }

    /* output */
    if (max>0) {
        if (max>MAXLEN) {
            if (tmp3) {
                printf ("%s", tmp3);
                free (tmp3);
                tmp3 = NULL;
            }
        }
        else
            printf ("%s", tmp1);
    }
}
