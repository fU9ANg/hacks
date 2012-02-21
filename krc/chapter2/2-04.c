#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

squeeze (char *s1, char *s2)
{
    int  i1, i2=0, f, i, j;
    char *t1=s1;
    char *t2=s2;

    while (*s2) {
        i1=f=0;
        while (i1<i2) {
            if (*s2==*(t2+i1++)) {
                f=1;
                break;
            }
        }
#if 1
        if (f==0) {
            i=j=0;
            i2++;
            s1=t1;
            while (*(s1+i)) {
                if (*(s1+i)!=*s2)
                    *(s1+j++) =*(s1+i);
                i++;
            }
            *(s1+j)='\0';
        }
#endif
        s2++;
    }
}

int getline (char *s, int max)
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
    int  l=0;

    if ((l=getline(line, MAXLEN)) > 0) {
        squeeze (line, "string");
        p=&line[0];

        while (*p)
            putchar (*p++);
    }
}
