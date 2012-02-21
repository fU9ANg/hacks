#include <stdio.h>

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 10;
    step  = 1;

    celsius = lower;
    printf ("The corresponding Fahrenheit to Celsius table\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf ("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
