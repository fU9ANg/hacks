
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
    char*   some_memory;
    int size_to_allocate = ONE_K;
    int megs_obtained = 0;
    int ks_obtained = 0;

    while (1) {
        for (ks_obtained = 0; ks_obtained < 1024; ks_obtained++) {
            some_memory = (char*) malloc (size_to_allocate);
            if (some_memory == NULL) exit (EXIT_FAILURE);
            sprintf (some_memory, "Hello world");
        }
        megs_obtained++;
        printf ("Now allocated %d Megabytes\n", megs_obtained);
    }

    exit (EXIT_SUCCESS);
}
