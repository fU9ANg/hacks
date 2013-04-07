#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 20

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
get_line (char d[], int max)
{
    int  i;
    char c;

/* For Exercise: 2-02 */
#if 0
    c=getchar();
    i=0;
    for (;;) {
        if (i<max-1) {
            if (c!=EOF) {
                if (c!='\n') {
                    d[i++]=c;
                } else
                    break;
            } else
                break;
        } else
            break;
    }
    if (c=='\n')
        d[i++]=c;
    d[i]='\0';
    return (i);
#endif

#if 0
    for (i=0; (i<max-1) && ((c=getchar()) != EOF) && (c!='\n'); i++) /*******/
        d[i]=c;
    if (c=='\n')
        d[i++]=c;

    d[i]='\0';
    return (i);
#endif

#if 1
    i=0;
    int n=0;
    for (;n==0;) {
        c=getchar();
        if (((c!='\n') ? ((c!=EOF) ? ((i<max-1) ? (d[i++]=c) : -1) : -1) : -1) == -1)
            break;
    }

    if (c=='\n')
        d[i++]=c;
    d[i]='\0';

    return (i);
#endif

}

main ()
{
    int  l=0, max=0;
    char line [MAXLEN];
    char tmp1 [MAXLEN], *tmp2=NULL, *tmp3=NULL, *tmp4=NULL;

    while ((l=get_line (line, MAXLEN))>0) {
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
