#include <stdio.h>
#include <stdlib.h>

int  li=1;
int  co=1;

void hm ();
void zs ();
void zsc();
void sy ();
void dy ();
void xk ();
void zk ();
void hk ();

void ERROR (char *s, int li, int co)
{
    printf ("[error]: line=%d, column=%d, in %s.\n", li, co, s);
}

/*
 *         "      "
 *  -> (1) -> (2) -> ((3))
 *     ^ |    ^ |
 *     |_|    |_|
 *     !"     !"
 *
 */
void sy()       /* "" */
{
#if 1
    char c;
    enum {
        S1=0,
        S2=1,
        S3=2    /* accept */
    } state;

    state=S1;
    while ((c=getchar()) != EOF) {
        if (state==S1) {
            if (c=='"')
                state=S2;
        }
        else if (state==S2) {
            if (c=='"')
                state=S3;
            else {
                if (c=='\\') {
                    ungetc (c, stdin);
                    hm ();
                }
            }
        }
        
        if ((c=='\r') || (c=='\n'))
            goto error;

        if (state==S3)
            return;

        co++;
    }

error:
    ERROR ("SY", li, co);
    exit (1);
#endif
}

/*
 *        '      !'     '
 * -> (1) -> (2) -> (3) -> ((4))
 *     |      |      |
 *     | !'   | '    | !'
 *     |______|______|
 *     v
 *    [5]
 */
void dy ()      /* '' */
{
#if 1
    char c;
    enum {
        S1=0,
        S2=1,
        S3=2,
        S4=4,   /* accept */
        S5      /* reject */
    } state;

    state=S1;
    while ((c=getchar()) != EOF) {
        if (state==S1) {
            if (c=='\'')
                state=S2;
            else
                state=S5;
        }
        else if (state==S2) {
            if (c=='\'')
                state=S5;
            else {
                if (c=='\\') {
                    ungetc (c, stdin);
                    hm ();
                }
                state=S3;
            }
        }
        else if (state==S3) {
            if (c=='\'')
                state=S4;
            else
                state=S5;
        }

        if ((c=='\r')||(c=='\n'))
            goto error;
        if (state==S4)
            return;
        if (state==S5)
            goto error;

        co++;
    }

error:
    ERROR ("DY", li, co);
    exit (1);
#endif
}

/*
 *        '/'    '*'    '*'    '/'
 * -> (1) -> (2) -> (3) -> (4) -> ((5))
 *     |      |     ^ |     |
 *     |!'/'  |!'*' |_|_____| !'/'
 *     |______|     !'*'
 *     v
 *    [6]
 *       
 */
void zs ()      /* / * * / */
{
    char c0, c1;
    enum {
        S1=0,
        S2=1,
        S3=2,
        S4=3,
        S5=4,   /* accept */
        S6      /* reject */
    } state;

    state=S1;
    while ((c0=getchar()) != EOF) {
        if (state==S1) {
            if (c0=='/')
                state=S2;
            else
                state=S6;
        }
        else if (state==S2) {
            if (c0=='*')
                state=S3;
            else
                state=S6;
        }
        else if (state==S3) {
            if (c0=='*')
                state=S4;
        }
        else if (state==S4) {
            if (c0=='/')
                state=S5;
            else {
                ungetc (c0, stdin);
                state=S3;
            }
        }

        if (c0=='\r') {
            if ((c1=getchar()) == '\n') {
                co=0;
                li++;
            }
            else {
                ungetc (c1, stdin);
                co=0;
                li++;
            }
        }
        if (c0=='\n') {
            co=0;
            li++;
        }
        if (state==S5)
            return;
        if (state==S6)
            goto error;

        co++;
    }
error:
    ERROR ("ZS", li, co);
    exit (1);
}

/*
 *         /      /      \n
 *  -> (1) -> (2) -> (3) -> ((4))
 *     ^ |     |     ^ |
 *     |_|     | !/  |_|
 *     !/      v     !\n
 *            [5]
 */   
void zsc()      // /*
{
    char c0;
    enum {
        S1=0,
        S2=1,
        S3=2,
        S4=3,   /* accept */
        S5      /* reject */
    } state;

    state=S1;
    while ((c0=getchar()) != EOF) {
        if (state==S1) {
            if (c0=='/')
                state=S2;
        }
        else if (state==S2) {
            if (c0=='/')
                state=S3;
            else
                state=S5;
        }
        else if (state==S3) {
            if (c0=='\n') {
                state=S4;
                ungetc (c0, stdin);
            }
        }

        if (state==S4)
            return;
        if (state==S5)
            goto error;
        co++;
    }
error:
    ERROR ("ZSC", li, co);
    exit (1);
}

/*
 *  A={a, b, f, n, r, t, v, \, ?, ', ", ooo, xhh}
 *         \      A
 *  -> (1) -> (2) -> ((3))
 *     ^ |     |
 *     |_|     | !A
 *     !\      v
 *            [4]
 */   
void hm ()      /* \X */
{
    char c0, c1, c2;
    enum {
        S1=0,
        S2=1,
        S3=2,   /* accept */
        S4=3    /* reject */
    } state;

    state=S1;
    while ((c0=getchar()) != EOF) {
        if (state==S1) {
            if (c0=='\\')
                state=S2;
        }
        else if (state==S2) {
            switch (c0) {
                case 'a':
                case 'b':
                case 'f':
                case 'n':
                case 'r':
                case 't':
                case 'v':
                case '\\':
                case '?':
                case '\'':
                case '\"':
                    state=S3;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    c1=getchar();
                    if ((c1>='0')&&(c1<='9')) {
                        c2=getchar();
                        if ((c2<'0')||(c2>'9'))
                            ungetc (c2, stdin);
                    } else
                        ungetc (c1, stdin);
                    state=S3;
                    break;
                case 'x':
                    c1=getchar();
                    if (isxdigit (c1)) {
                        c2=getchar();
                        if (!isxdigit (c2))
                            ungetc (c2, stdin);
                        state=S3;
                    } else {
                        ungetc (c1, stdin);
                        state=S4;
                    }
                    break;
                case '\n':
                    state=S3;
                    ungetc (c0, stdin);
                    break;
                case '\r':
                    state=S3;
                    break;
                default:
                    state=S4;
            }
        }
        
        if (state==S3)
            return;
        if (state==S4)
            goto error;
    }
error:
    ERROR ("hm", li, co);
    exit (1);
}

/*
 *         (      )
 *  -> (1) -> (2) -> ((3))
 *      |     ^ |
 *      | !(  |_|
 *      v      !)
 *     [4]
 */   
void xk ()      /* () */
{
    char c0, c1;
    enum {
        S1=0,
        S2=1,
        S3=2,   /* accpet */
        S4=3    /* reject */
    } state;

    state=S1;
    while ((c0=getchar()) != EOF) {
        if (state==S1) {
            if (c0=='(')
                state=S2;
            else
                state=S4;
        }
        else if (state==S2) {
            switch (c0) {
                case '"':
                    ungetc (c0, stdin);
                    sy ();
                    break;
                case '\'':
                    ungetc (c0, stdin);
                    dy ();
                    break;
                case '\\':
                    ungetc (c0, stdin);
                    hm ();
                    break;
                case '(':
                    ungetc (c0, stdin);
                    xk ();
                    break;
                case '[':
                    ungetc (c0, stdin);
                    zk ();
                    break;
                case '{':
                    ungetc (c0, stdin);
                    hk ();
                    break;
                case '/':
                    if ((c1=getchar()) == '*') {
                        ungetc (c1, stdin);
                        ungetc (c0, stdin);
                        zs ();
                    }
                    else if (c1 == '/') {
                        ungetc (c1, stdin);
                        ungetc (c0, stdin);
                        zsc();
                    }
                    else
                        ungetc (c1, stdin);
                    break;
                case '*':
                    if ((c1=getchar()) == '/')
                        goto error;
                    else
                        ungetc (c1, stdin);
                    break;
                case ']':
                case '}':
                    goto error;
                case ')':
                    state=S3;
                    break;
                case '\r':
                    if ((c1=getchar()) == '\n') {
                        co=0;
                        li++;
                    }
                    else {
                        ungetc (c1, stdin);
                        co=0;
                        li++;
                    }
                    break;
                case '\n':
                    co=0;
                    li++;
                    break;
                default:
                    state=S2;
            }
        }

        if (state==S3)
            return;
        if (state==S4)
            goto error;
    }
error:
    ERROR ("xk", li, co);
    exit (1);
}

/*
 *         [      ]
 *  -> (1) -> (2) -> ((3))
 *      |     ^ |
 *      | ![  |_|
 *      v      !]
 *     [4]
 */   
void zk ()      /* [] */
{
    char c0, c1;
    enum {
        S1=0,
        S2=1,
        S3=2,   /* accept */
        S4=3    /* reject */
    } state;

    state=S1;
    while ((c0=getchar()) != EOF) {
        if (state==S1) {
            if (c0=='[')
                state=S2;
            else
                state=S4;
        }
        else if (state==S2) {
            switch (c0) {
                case '"':
                    ungetc (c0, stdin);
                    sy ();
                    break;
                case '\'':
                    ungetc (c0, stdin);
                    dy ();
                    break;
                case '\\':
                    ungetc (c0, stdin);
                    hm ();
                    break;
                case '(':
                    ungetc (c0, stdin);
                    xk ();
                    break;
                case '[':
                    ungetc (c0, stdin);
                    zk ();
                    break;
                case '{':
                    ungetc (c0, stdin);
                    hk ();
                    break;
                case '/':
                    if ((c1=getchar()) == '*') {
                        ungetc (c1, stdin);
                        ungetc (c0, stdin);
                        zs ();
                    }
                    else if (c1 == '/') {
                        ungetc (c1, stdin);
                        ungetc (c0, stdin);
                        zsc();
                    }
                    else
                        ungetc (c1, stdin);
                    break;
                case '*':
                    if ((c1=getchar()) == '/')
                        goto error;
                    else
                        ungetc (c1, stdin);
                    break;
                case ')':
                case '}':
                    goto error;
                case ']':
                    state=S3;
                    break;
                case '\r':
                    if ((c1=getchar()) == '\n') {
                        co=0;
                        li++;
                    }
                    else {
                        ungetc (c1, stdin);
                        co=0;
                        li++;
                    }
                    break;
                case '\n':
                    co=0;
                    li++;
                    break;
                default:
                    state=S2;
            }
        }

        if (state==S3)
            return;
        if (state==S4)
            goto error;
    }
error:
    ERROR ("zk", li, co);
    exit (1);
}

/*
 *         {      }
 *  -> (1) -> (2) -> ((3))
 *      |     ^ |
 *      | !{  |_|
 *      v      !}
 *     [4]
 */   
void hk ()      /* {} */
{
    char c0, c1;
    enum {
        S1=0,
        S2=1,
        S3=2,   /* accept */
        S4=3    /* reject */
    } state;

    state=S1;
    while ((c0=getchar()) != EOF) {
        if (state==S1) {
            if (c0=='{')
                state=S2;
            else
                state=S4;
        }
        else if (state==S2) {
            switch (c0) {
                case '"':
                    ungetc (c0, stdin);
                    sy ();
                    break;
                case '\'':
                    ungetc (c0, stdin);
                    dy ();
                    break;
                case '\\':
                    ungetc (c0, stdin);
                    hm ();
                    break;
                case '(':
                    ungetc (c0, stdin);
                    xk ();
                    break;
                case '[':
                    ungetc (c0, stdin);
                    zk ();
                    break;
                case '{':
                    ungetc (c0, stdin);
                    hk ();
                    break;
                case '/':
                    if ((c1=getchar()) == '*') {
                        ungetc (c1, stdin);
                        ungetc (c0, stdin);
                        zs ();
                    }
                    else if (c1 == '/') {
                        ungetc (c1, stdin);
                        ungetc (c0, stdin);
                        zsc();
                    }
                    else
                        ungetc (c1, stdin);
                    break;
                case '*':
                    if ((c1=getchar()) == '/')
                        goto error;
                    else
                        ungetc (c1, stdin);
                    break;
                case ']':
                case ')':
                    goto error;
                case '}':
                    state=S3;
                    break;
                case '\r':
                    if ((c1=getchar()) == '\n') {
                        co=0;
                        li++;
                    }
                    else {
                        ungetc (c1, stdin);
                        co=0;
                        li++;
                    }
                    break;
                case '\n':
                    co=0;
                    li++;
                    break;
                default:
                    state=S2;
            }
        }

        if (state==S3)
            return;
        if (state==S4)
            goto error;
    }
error:
    ERROR ("hk", li, co);
    exit (1);
}

main ()
{
    char c0, c1;
    while ((c0=getchar()) != EOF) {
        switch (c0) {
            case '"':
                ungetc (c0, stdin);  /* go back `bitch' */
                sy ();
                break;
            case '\'':
                ungetc (c0, stdin);
                dy ();
                break;
            case '\\':
                ungetc (c0, stdin);
                hm ();
                break;
            case '(':
                ungetc (c0, stdin);
                xk ();
                break;
            case '[':
                ungetc (c0, stdin);
                zk ();
                break;
            case '{':
                ungetc (c0, stdin);
                hk ();
                break;
            case '/':
                if ((c1=getchar()) == '*') {
                    ungetc (c1, stdin);
                    ungetc (c0, stdin);
                    zs ();
                }
                else if (c1=='/') {
                    ungetc (c1, stdin);
                    ungetc (c0, stdin);
                    zsc();
                }
                else
                    ungetc (c1, stdin);
                break;
            case '*':
                if ((c1=getchar()) == '/') {
                    ERROR ("main", li, co);
                    return;
                }
                else
                    ungetc (c1, stdin);
                break;
            case ')':
            case ']':
            case '}':
                ERROR ("main", li, co);
                return;
            case '\r':
                if ((c1=getchar()) == '\n') {
                    co=0;
                    li++;
                }
                else {
                    ungetc (c1, stdin);
                    co=0;
                    li++;
                }
                break;
            case '\n':
                co=0;
                li++;
                break;
            default :
                ;
        }
        co++;
    }
}
