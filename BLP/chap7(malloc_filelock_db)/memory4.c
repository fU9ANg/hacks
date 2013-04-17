
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
    char* scan_ptr;

    some_memory = (char*) malloc (ONE_K);
    if (some_memory == NULL) exit (EXIT_FAILURE);

    scan_ptr = some_memory;
    while (1)
    {
        *scan_ptr = 0x00;
        scan_ptr++;
    }

    exit (EXIT_SUCCESS);
}
