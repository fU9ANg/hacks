

// 使用位操作将实现*或者/操作
#include <stdio.h>

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf ("usage: %s number.\n", *argv);
        return (1);
    }

    int number = atoi (*(argv+1));
    if (number > 0)
    {
        printf ("number >> 1 = %d, number << 1 = %d\n", 
                number >> 1, number << 1);

        return (0);
    }

    return (1);
}
