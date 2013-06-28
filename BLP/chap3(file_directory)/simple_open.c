#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main ()
{
    char c;
    int i, o;

    i = open ("simple_open.c", O_RDONLY);
    o = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while (read (i, &c, 1) == 1)
        write (o, &c, 1);

    exit (EXIT_SUCCESS);
}
