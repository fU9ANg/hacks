// 使用位操作将实现对一个数的二进制位数统计

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
        while (num1)
        {
            if (num1 & 0x01) cnt++;
            num1 >>= 1;
        }

        printf ("bitcount of number: %d\n", cnt);
        return (0);
    }

    return (1);
}
