#include <stdio.h>
#include <string.h>

#define TBL_LEN 128

void f14 ()
{
    char c;
    int i=0, ascii_tbl[TBL_LEN];
    memset (ascii_tbl, 0, sizeof (ascii_tbl));

    while (((c=getchar()) != EOF) && \
            (isascii (c))) ascii_tbl[c]++;

    for (i=0; i<TBL_LEN; i++)
        if (ascii_tbl[i]>0)
            printf ("character[%c, 0x%x]: count=%d\n", i, i, ascii_tbl[i]);
}


int main ()
{
    f14 ();
}
