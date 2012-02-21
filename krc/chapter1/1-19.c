#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN     1

void reverse (char *s)
{
    char *p1=s, *p2=s+strlen(s)-1;
    char t;

    void _reverse (char *p1, char *p2) {
        if (p1<p2) {
            t=*p1;
            *p1=*p2;
            *p2=t;
            _reverse(++p1, --p2);
        }
    }

    _reverse (p1, p2);
}

copy (char d[], char s[])
{
    int i=0;

    while (s[i] != '\0')
        d[i]=s[i++];
    d[i]='\0';
}

int main()
{
    int  i=0;
    char c;
    char *t1=NULL, *t2=NULL, *t3=NULL;

    while ((c=getchar()) != EOF) {
        if (c=='\n') {
            if (t1) {
                *(t1+i)='\0';
                t3=t1;
                reverse (t1);
                while (*t1) putchar (*t1++);
                putchar ('\n');
                free (t3);
                t1 = t3 = NULL;
            } else
                putchar ('\n');
        } else {
            if (!t1) {
                t1 = (char*) calloc (sizeof (char), LEN+1);
                i  = 0;
            }
/* *\t***** */
/**a**b\b**/
/* *"*"*'*'*/
/***#deifne** */

//cront ab is used
//01234 56789
            if ((i+1)%LEN == 0) {
                *(t1+i)   =c;
                *(t1+i+1) ='\0';
                t2 = (char*) calloc (sizeof (char), LEN+strlen(t1)+1);
                t3 = t1;
                copy (t2, t1);
                t1 = t2;
                if (t3)
                    free (t3);
                t2 = t3 = NULL;
            } else {
                *(t1+i) = c;
            }
        }
        i++;
    } //
}
