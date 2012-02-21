#include <stdio.h>
#include <string.h>

int f2c (int f)
{
    return (5*(f-32)/9);
}

int main (int argc, char **argv)
{
    if (argc < 3) {
        printf ("Usage: `programName %%lower %%upper %%step'\n");
        return 0;
    }

    int fahr, celsius;
    int lower, upper, step;

    lower = atoi (*++argv);
    upper = atoi (*++argv);
    step  = atoi (*++argv);

    fahr = lower;
    while (fahr<=upper) {
        celsius=f2c(fahr);
        printf ("%d\t%d\n", fahr, celsius);
        fahr+=step;
    }
}
