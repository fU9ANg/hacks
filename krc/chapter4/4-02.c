#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double _atof(char s[])
{
    double val, power;
    int i, sign, num, flag;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
#if 1
    if (s[i]=='e' || s[i]=='E')
        i++;
    if ((s[i] == '-') || (s[i] == '+')){
        if (s[i] == '-')
            flag=-1;
        else
            flag=1;
        i++;
    } else
        flag=1;
        
    for (num = 0; isdigit(s[i]); i++)
        num = num * 10 + (s[i] - '0');
    
    num *= flag;
    while (num<0) {
        power *= 10;
        num++;
    }
    while (num>0) {
        val *= 10;
        num--;
    }
#endif
    return sign * val / power;
}

main(int argc, char **argv)
{
    if (argc < 2) {
        printf ("Usage: %s `float-string'.\n", *argv);
        return (1);
    }
    printf ("%g\n", _atof (*(argv+1)));
}
