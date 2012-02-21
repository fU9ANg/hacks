#include <stdio.h>
#include <stdlib.h>

#define MAXLEN  128

int adesc (char t[], char c, int flag)
{
    int  i=0;

    if (flag==1) {
        while (t[i]<=c) {
            t[i+1]=t[i]+1;
            i++;
        }
        t[i]='\0';
    }
    else if (flag==0) {
        while (t[i]>=c) {
            t[i+1]=t[i]-1;
            i++;
        }
        t[i]='\0';
    }
    return (i-1);
}

expand (char s1[], char s2[])
{
    int  i=0, j=0, flag=0;
    int  p=0;

    while (s1[i]) {
        if (s1[i]=='-') {
            if (i>0) {
                flag=1;
            }
        }
        else {
            /* FIXME: */
            if (isalnum(s1[i])) {   /* number and character */
                if (flag) {
                    if (isdigit (s2[p])) {
                        if (isdigit (s1[i])) {
                            if ((s2[p])<s1[i])      /* asc  */
                                p=j=j-1+adesc (&s2[p], s1[i], 1);
                            else                    /* desc */
                                p=j=j-1+adesc (&s2[p], s1[i], 0);
                        } else {
                            s2[j]=s1[i];
                            p=j;
                        }
                    }
                    else if (islower (s2[p])) {
                        if (islower (s1[i])) {
                            if ((s2[p])<s1[i])      /* asc  */
                                p=j=j-1+adesc (&s2[p], s1[i], 1);
                            else                    /* desc */
                                p=j=j-1+adesc (&s2[p], s1[i], 0);
                        } else {
                            s2[j]=s1[i];
                            p=j;
                        }
                    }
                    else if (isupper (s2[p])) {
                        if (isupper (s1[i])) {
                            if ((s2[p])<s1[i])      /* asc  */
                                p=j=j-1+adesc (&s2[p], s1[i], 1);
                            else                    /* desc */
                                p=j=j-1+adesc (&s2[p], s1[i], 0);
                        } else {
                            s2[j]=s1[i];
                            p=j;
                        }
                    }
                    flag=0;
                }
                else {
                    s2[j]=s1[i];
                    p=j;
                }
            }
            j++;
        }
        i++;
    }
    s2[j]='\0';
}

main (int argc, char **argv)
{
    if (argc<2) {
        printf ("Usage: %s `expression'.\n", *argv);
        exit (1);
    }

    char s2[MAXLEN]="a";
    expand (*(argv+1), s2);
    //adesc (s2, 'e', 1);
    printf ("Expression: `%s' expand is: `%s'.\n", \
            *(argv+1), s2);
}
