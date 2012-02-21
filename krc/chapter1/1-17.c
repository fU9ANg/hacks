#include <stdio.h>
#include <string.h>

#define LINE_LEN 20

void print_line (char l[], int max)
{
    int i=0;
    while (i<max)
        putchar (l[i++]);
}

void f17 ()
{
    char c, line[LINE_LEN];
    int  i=0, j=0, flag=0;
    while ((c=getchar()) != EOF) {

        if (c=='\n') {
            if (flag)
                putchar ('\n');
            i=flag=0;
            continue;
        } else {
            if (flag)
                putchar (c);
            else
                line[i]=c;
        }

        if ((i==LINE_LEN-1) && (!flag)) {
            print_line (line, LINE_LEN);
            flag=1;
        }
        i++;
    }
}


int main()
{
    f17 ();
}
