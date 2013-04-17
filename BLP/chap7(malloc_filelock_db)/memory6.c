
// 2009 - 2013
//
// by fU9ANg
// bb.newlife@gmail.com

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define ONE_K   (1024)

int main (int argc, char** argv)
{
    char* some_memory;
    int exit_code = EXIT_FAILURE;

    some_memory = (char*) malloc (ONE_K);
    if (some_memory != NULL) {
        free (some_memory);
        exit_code = EXIT_SUCCESS;
    }

    exit (exit_code);
}
