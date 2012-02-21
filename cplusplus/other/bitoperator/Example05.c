// 使用位操作将实现% (mod)操作

#include <stdio.h>

int main (int argc, char **argv)
{
    if (argc != 3)
    {
        printf ("usage: %s number1 number2.\n", *argv);
        return (1);
    }

    int num1 = atoi (*(argv+1));
    int num2 = atoi (*(argv+2));
    int temp = 0;
    if (num1 > 0 && num2 > 0)
    {
        temp = num1 & (num2 - 1);   // FIXME: only use by 2^n
        printf ("%d, %d\n", num1, num2);
        printf ("num1 mod num2 = %d, %d\n",
                temp, (num1 % num2));

        return (0);
    }

    return (1);
}
