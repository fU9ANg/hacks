
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 64

int main ()
{
    char data[MAX_DATA];
    int  data_len;

    sprintf (data, "%s\n", "Here is some data");
    data_len = strlen (data);
    if ((write (1, data, data_len)) != data_len)
        write (2, "A write error has occurred on file descriptor 1\n", 46);

    exit (0); 
}
