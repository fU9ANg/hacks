#include <stdio.h>
#include <limits.h>

main()
{
    printf ("bits in a char: %d\n", CHAR_BIT);
    printf ("maximum value of char : %d, %d, %d\n", CHAR_MAX, UCHAR_MAX, SCHAR_MAX);
    printf ("minimum value of char : %d, %d, %d\n", CHAR_MIN, 0, SCHAR_MIN);
    printf ("maximum value of signed char: %d\n", SCHAR_MAX);
    printf ("minimum value of signed char: %d\n", SCHAR_MIN);
    printf ("maximum value of int  : %d\n", INT_MAX);
    printf ("minimum value of int  : %d\n", INT_MIN);
    printf ("maximum value of long : %d\n", LONG_MAX);
    printf ("minimum value of long : %d\n", LONG_MIN);
    printf ("maximum value of short: %d\n", SHRT_MAX);
    printf ("minimum value of short: %d\n", SHRT_MIN);
    printf ("maximum value of unsigned char : %d\n", UCHAR_MAX);
    printf ("maximum value of unsigned int  : %lu\n", UINT_MAX);
    printf ("maximum value of unsigned long : %lu\n", ULONG_MAX);
    printf ("maximum value of unsigned short: %d\n", USHRT_MAX);
}
