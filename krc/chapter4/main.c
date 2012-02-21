#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>

#define MAXOP   100
#define MAXVAL  100
#define BUFSIZE 100
#define NUMBER  '0'

char    buf[BUFSIZE];
int     bufp=0, sp=0;
double  val[MAXVAL];

double push (double f)
{
    if (sp < MAXVAL)
        val[sp++]=f;
    else
        printf ("error: stack null, can't push %g\n", f);
}

double pop (void)
{
    if (sp > 0)
        return (val[--sp]);
    else {
        printf ("error: stack empty\n");
        return 0.0;
    }
}

int getch (void)
{
    return (bufp>0) ? buf[--bufp] : getchar ();
}

void ungetch (int c)
{
    if (bufp >= BUFSIZE)
        printf ("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}

int getop (char s[])
{
    int i, c;
    while ((s[0] = c = getch ()) == ' ' || c == '\t') ;

    s[1]='\0';

    if (!isdigit (c) && c != '.') {
        if (c=='-') {
            s[1]=c=getch ();
            if (isdigit (c))
                s[2]='\0';
            else {
                ungetch (c);
                return ('-');
            }
        }
        else
            return (c);
    }

    i=strlen (s)-1;
    if (isdigit (c))
        while (isdigit (s[++i]=c=getch ())) ;

    if (c=='.')
        while (isdigit (s[++i]=c=getch ())) ;

    s[i]='\0';

    if (c != EOF)
        ungetch (c);

    return NUMBER;
}

main ()
{
    int     type;
    double  op2;
    char    s[MAXOP];

    while ((type = getop (s)) != EOF) {
        switch (type) {
            case NUMBER:
                push (atof (s));
                break;
            case '+':
                push (pop () + pop ());
                break;
            case '*':
                push (pop () * pop ());
                break;
            case '-':
                op2=pop ();
                push (pop () - op2);
                break;
            case '/':
                op2=pop ();
                if (op2 != 0)
                    push (pop () / op2);
                else
                    printf ("error: division by zero\n");
                break;
            case '%':
                op2=pop ();
                if (op2 != 0)
                    push ((int)pop () % (int)op2);
                else
                    printf ("error: division by zero\n");
                break;
            case '\n':
                printf ("\t%.8g\n", pop ());
                break;
            default:
                printf ("error: unknown command %s\n", s);
                break;
        }
    }
    return (0);
}
