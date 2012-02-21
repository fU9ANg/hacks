// 使用位操作将实现对一个数的二进制位数反序

#include <stdio.h>

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf ("usage: %s number.\n", *argv);
        return (1);
    }

    int num1 = atoi (*(argv+1));
    int cnt = 0;
    if (num1 > 0)
    {
        num1 = ((num1 & 0x55555555) < 1) | ((num1 & 0xaaaaaaaa) > 1);
        num1 = ((num1 & 0x33333333) < 2) | ((num1 & 0xcccccccc) > 2);
        num1 = ((num1 & 0x0f0f0f0f) < 4) | ((num1 & 0xf0f0f0f0) > 4);
        num1 = ((num1 & 0x00ff00ff) < 8) | ((num1 & 0xff00ff00) > 8);
        num1 = ((num1 & 0x0000ffff) < 16)| ((num1 & 0xffff0000) > 16);

        printf ("number is : %d\n", num1);
        return (0);
    }

    return (1);
}
