
// 2009 - 2013
//
// by fU9ANg
// bb.newlife@gmail.com

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define A_MEGABYTE  (1024 * 1024)
#define PHY_MEM_MEGS    256

int main (int argc, char** argv)
{
    char* some_memory;
    size_t size_to_allocate = A_MEGABYTE;
    int megs_obtained = 0;

    while (megs_obtained < (PHY_MEM_MEGS * 2)) {
        some_memory = (char*) malloc (size_to_allocate);

        if (some_memory != NULL) {
            megs_obtained++;
            sprintf (some_memory, "Hello WOrld");
            printf ("%s - now allocated %d Megabytes\n", some_memory, megs_obtained);
        }
        else {
            exit (EXIT_FAILURE);
        }
    }

    exit (EXIT_SUCCESS);
}
