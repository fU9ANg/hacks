#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 200
#define TABLEN 8

/* Question: `What do you think of the word 'f**king', and why?' */
/* Answer  : `That's my favorite word.' */
int
getline (char d[], int max)
{
    int  i;
    char c;

    for (i=0; (i<max-1) && ((c=getchar()) != EOF) && (c!='\n'); i++) /*****/
        d[i]=c;
    if (c=='\n')
        d[i++]=c;

    d[i]='\0';
    return (i);
}

pntspc (int n)
{
    if (n>0) {
        putchar (0x20);
        pntspc  (n-1);
    }
}

/* `Who can't write an OS in a week? */
main ()
{
    int  l, i=0;
    char line [MAXLEN], *p=NULL;

    //pntspc (10);
    while ((l=getline (line, MAXLEN))>0) {
        p=&line[0];
        i=0;
#if 1
        while (*p) {
            if (i<TABLEN) {
                if (*p=='\t') {
                    if (TABLEN-i)
                        pntspc (TABLEN-i);
                    else
                        pntspc (TABLEN);
                    i=0;
                } else {
                    putchar (*p);
                    i++;
                    if (i==TABLEN) i=0;
                }
            }
            p++;
        }
#endif
    }

}
