

// 使用位操作将奇数变成小于它的最大偶数
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
        // 使用｜操作, 将一个数末尾加0x01, 然后再减1
        printf ("number is: %s, even is: %d\n", *(argv+1), (num | 0x01) - 1);

        return (0);
    }

    return (1);
}
