#include <stdio.h>


int wc(FILE *, char *);

int
main(argc, argv) 
int argc;
char **argv; {

	FILE *fp = stdin;

	if(argc > 1) {
		while(--argc) {
			if((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stdout, "can't open %s.\n", *argv);
				return(1);
			}else{
				wc(fp, *argv);
				fclose(fp);
			}
		}
	}else
		wc(fp, "stdin");

	return(0);
}


int 
wc(fd, file)
FILE *fd;
char *file; {
		
	char c;
	long charct = 0, wordct = 0, linect = 0, token = 0;
	while((c=getc(fd)) != EOF) {
		charct++;
		if(0x20<c&&c<127) {
			if(!token) {
				wordct++;
				token = 1;
			}
			continue;
		}
		if(c=='\n')
			linect++;
		else if(c!=' '&&c!='\t')
			continue;
		token = 0;
		}
		printf("%6ld %6ld %6ld %s\n", linect, wordct, charct, file);

	return(0);
}
