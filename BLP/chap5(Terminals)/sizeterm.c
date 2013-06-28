// Using terminfo Capabilities

#include <stdio.h>
#include <term.h>
#include <ncurses.h>

int main()
{
    int nrows, ncolumns;
    setupterm(NULL, fileno(stdout), (int *)0);
    nrows = tigetnum("lines");
    ncolumns = tigetnum("cols");
    printf("This terminal has %d columns and %d rows\n", ncolumns, nrows);
    exit(0);
}

#if 0
$ echo $TERM
vt100
$ sizeterm
This terminal has 80 columns and 24 rows
$
#endif

