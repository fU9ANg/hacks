
// 2009 - 2013
//
// by fU9ANg
// bb.newlife@gmail.com

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    char z = *(const char*) 0;
    printf ("I read from location zero\n");
    exit (EXIT_SUCCESS);
}
