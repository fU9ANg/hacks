#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN  500
#define EXPLEN  50

int _strrindex(char s[], char t[])
{
    int i, j, k, l;
    i=strlen (s)-1;
    l=strlen (t)-1;

    for (; i!=-1; i--) {
        for (j=i, k=l; ((k!=-1) && (s[j]==t[k])); j--, k--) ;
        if (k==-1)
            return j+2;
    }

    return -1;
}

int main (int argc, char **argv)
{
	char *e=NULL, exp[EXPLEN];
	int   se=1;
	int   i, len;

    if (argc < 3) {
        printf ("Usage: %s `main-string' `sub-string'.\n", *argv);
        return (1);
    }

    printf ("%d\n", _strrindex (*(argv+1), *(argv+2)));
}

#if 0
int main (int argc, char **argv)
{
	char *e=NULL, exp[EXPLEN];
	int   se=1;
	int   i, len;

    if (argc < 2) {
        printf ("Usage: %s `expression'.\n", *argv);
        return (1);
    }

	strcpy (exp, *(argv+1));
    reverse (exp);
	if ((len=strlen (exp)) < 1) {
		printf ("Input express is error.\n");
		return (1);
	}

    char *p=NULL;
    int   l=0, li=0, co=0;
    char  line[MAXLEN], content[MAXLEN];
    while ((l=getline(line, MAXLEN)) > 0) {
        li++;
        strcpy (content, line);
        p=&line[0];
        reverse (line);
		se=1;
        co=0;
        while (*p) {
            co++;
			i=1;
			e=&exp[0];
			while (i <= len) {
				if (se == i) {
					if (i==1) {
						if (*p==*e)
							se = i+1;
						else
							se = 1;
					}
					else {
						if (*p==*(e+i-1))
							se = i+1;
						else if (*p==*e)
							se = 2;
						else
							se = 1;
					}
					break;
				}
				if (i++ > len) {
					printf ("The state machine is error.\n");
					return (1);
				}
				//e++;
			} //
			if (se==(len+1)) {
				printf ("Line(%-4d, %-4d): %s", li, l-co+1, content);
				break;
			}
			p++;
		}
	}
}

reverse (char s[])
{
    char tmp, *p1=&s[0], *p2=&s[strlen(s)-1];
    
    void _reverse (char *p1, char *p2) {
        if (p1 < p2) {
            tmp=*p1;
            *p1=*p2;
            *p2=tmp;
            _reverse (++p1, --p2);
        }
    }

    _reverse (p1, p2);
}

int getline (char d[], int max)
{
    int  i;
    char c;

    for (i=0; (i<max-1) && ((c=getchar()) != EOF) && (c!='\n'); i++)
        d[i]=c;
    if (c=='\n')
        d[i++]=c;
    d[i]='\0';
    return (i);
}
#endif
