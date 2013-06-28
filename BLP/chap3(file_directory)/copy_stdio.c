
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int c;
    FILE* in, *out;

    in = fopen ("copy_stdio.c", "r");
    out = fopen ("file.out", "w");

    while ((c = fgetc (in)) != EOF)
        fputc (c, out);

    exit (EXIT_FAILURE);
}
