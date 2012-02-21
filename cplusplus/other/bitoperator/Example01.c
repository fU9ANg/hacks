

// 使用位操作判断奇偶数
#include <stdio.h>

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf ("usage: %s number.\n", *argv);
        return (1);
    }

    int num = atoi (*(argv+1));
    if (num > 0)
    {
        if (num & 0x01) // 使用&, 检查最后一位二进制数是不否是 1
            printf ("odd\n");
        else
            printf ("even\n");

        return (0);
    }

    return (1);
}
