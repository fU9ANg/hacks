

// 使用位操作将两个整数交换值
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
    if (num1 > 0 && num2 > 0)
    {
        printf ("before of swap: number1 is: %d, number2 is: %d\n",
                num1, num2);

        // 使用^, 变换两个整数的值, 因为一个数两次异或的结果就是自已.
        num1 = num1 ^ num2;
        num2 = num1 ^ num2;
        num1 = num1 ^ num2;

        printf ("after of swap: number1 is: %d, number2 is: %d\n",
                num1, num2);

        return (0);
    }

    return (1);
}
