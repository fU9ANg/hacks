/*	
 *	Delete empty line
 *	H. F. G. fU9ANg (bb.newlife@gmail.com)
 *	HackerFellowShip
 */

#include <stdio.h>
#define		MAXSIZE		1000

int 
getline(s, lim) 
	char *s;
	int  lim; {
        int  i = 0;
        char c;
        for(; (i < lim-1) && ((c=getchar()) != EOF); i++) {
                s[i] = c;
                if(c == '\n')
                        goto out;
        }

out:
        s[++i] = '\0';
        return(c);
}

int
main() {
	char s[MAXSIZE];
	
	while(getline(s, MAXSIZE) != EOF) {
		if(*s == '\n')	
			continue;
        	else
			printf("%s", s);
 	}
        /*int c;
        while((c = getchar()) != EOF) {
                if(c == ' ')
                        printf("\\space");
                if(c == '\b')
                        printf("\\b");
                if(c == '\t')
                        printf("\\t");
                if(c == '\n')
                        printf("\\n");
                if(c == '\\')
                        printf("\\\\");
                else
                        putchar(c);
        }
        printf("\n");*/
}
