#include <stdio.h>
#include <string.h>

#define LINE_LEN 120

void f18 ()
{
    char line[LINE_LEN], *p=NULL, c;
    int i=0, ipos=-1, sf=0;
    memset (line, 0, sizeof (line));

    while ((c=getchar()) != EOF) {
        /* if ((c==0x0a)||(c==0x0d)) { */
        if (c==0x0a) {
            if(ipos==-1) {
                line[i]='\n';
                line[i+1]='\0';
            } else {
                if (sf) {
                    line[ipos]='\n';
                    line[ipos+1]='\0';
                } else
                    line[ipos]='\0';
            }

            /* output */
            p=&line[0];
            while (*p)
                putchar (*p++);

            i=sf=0;
            ipos=-1;
            memset (line, 0, sizeof (line));
        } else {
            if ((c==0x09) || (c==0x20)) {
                if (ipos==-1)
                    ipos=i;
            } else {
                sf=1;
                ipos=-1;
            }

            line[i++]=c;
        }

        /* error */
        if (i>LINE_LEN) {
            printf ("out of `LINE_LEN'\n");
            return;
        }
    }
}


int main ()
{
    f18 ();
}
