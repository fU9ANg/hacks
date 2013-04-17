
// 2009 - 2013
//
// by fU9ANg
// bb.newlife@gmail.com

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    char* some_memory = (char*) 0;

    printf ("A read from null %s\n", some_memory);
    sprintf (some_memory, "A write to null\n");
    exit (EXIT_SUCCESS);
}
