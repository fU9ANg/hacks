
// 2009 - 2013
//
// by fU9ANg
// bb.newlife@gmail.com

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define A_MEGABYTE  (1024 * 1024)

int main (int argc, char** argv)
{

    char* some_memory;
    int   megabyte = A_MEGABYTE;
    int   exit_code = EXIT_FAILURE;

    if ((some_memory = (char*) malloc (megabyte)) != NULL) {
        sprintf (some_memory, "hello world\n");
        printf ("%s", some_memory);
        exit_code = EXIT_SUCCESS;
    }

    exit (exit_code);
}
