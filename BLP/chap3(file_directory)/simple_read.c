
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 128

int main()
{
    char buffer[MAX_BUFFER];
    int nread;

    nread = read (0, buffer, MAX_BUFFER);
    if (nread == -1)
        write (2, "A read error has occurred\n", 26);
    if ((write (1,buffer,nread)) != nread)
        write (2, "A write error has occurred\n",27);

    exit (EXIT_SUCCESS);
}
