#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int any (char *s1, char *s2)
{
    int  i1=0, i2=0, f, i;
    char *t1=s1;
    char *t2=s2;

    if ((!t1)||(!t2))
        return (-1);

    while (*s1) {
        i1=f=0;
        while (i1<i2) {     /* check exists */
            if (*s1==*(t1+i1++)) {
                f=1;
                break;
            }
        }

        if (!f) {           /* compare */
            i=0;
            s2=t2;
            while (*(s2+i)) {
                if (*(s2+i)==*s1)
                    return (i2+1);
                i++;
            }
        }
        i2++;
        s1++;
    }
    return (-1);
}

int get_line (char *s, int max)
{
    int  i=0;
    char c;
  
    for (i=0; ((i<max-1) && ((c=getchar())!=EOF) && (c!='\n')); i++)
        s[i]=c;
    if (c=='\n')
        s[i++]='\n';
    s[i]='\0';

    return (i);
}

int main(int argc, char **argv)
{
    char line[MAXLEN], *p=NULL;
    int  l=0, num=0;

    while ((l=get_line(line, MAXLEN)) > 0) {
        num++;
        printf ("line:%-2d, first location=%3d\n", num, any (line, "string"));
    }
}
