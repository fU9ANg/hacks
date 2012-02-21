#include <stdio.h>
#include <stdlib.h>

#define MAXLEN  256

print_line (char p[], int len)
{
    int  i=0;
    while (i<len)
        putchar (p[i++]);
}

main(int argc, char **argv)
{
    char c, tmp[MAXLEN];
    int  col=0;
    int  i=0, j=0;
    if (argc==1) {
        printf ("[error]: %s `column (>1)`\n", *argv);
        exit (1);
    }
    if ((col=atoi(*++argv))<2) {
        printf ("[error]: %s `column (>1)`\n", *argv);
        exit (1);
    }
    

    while ((c=getchar()) != EOF) {
        i++;
        if (c!=' ') {               /* !space */
            if (i<col) {
                if (j>0) {
                    print_line (tmp, j);
                    j=0;
                }
                if (c=='\n')
                    i=0;
                putchar (c);
            }
            else {
                if (c=='\n') {
                    if (j>0) {
                        print_line (tmp, j);
                        j=0;
                    }
                    putchar (c);
                    i=0;
                }
                else {
                    putchar ('\n');
                    i=j+1;
                    if (j>0) {
                        print_line (tmp, j);
                        j=0;
                    }
                    putchar (c);
                }
            }
        } else {                    /* space  */
            if (i>=col) {
                putchar ('\n');
                i=j+1;
            }
            tmp[j++]=c;
            tmp[j]='\0';
            if ((j+1)>=col) {
                i=0;
                print_line (tmp, j);
                putchar ('\n');
                j=0;
            }
        }
    }
}
