/*	
 *	Delete memo of c source code
 *	H. F. G. fU9ANg(bb.newlife@gmail.com)
 *	HackerFellowShip
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#define 	MAXLINE		1000
int
delmem(void) {

	char c, tempc;
	int  preflag = 0;
	int  endflag = 0;
	int  inmemo  = 0;

	while((c=getchar()) != EOF) {
		if((!inmemo) && (c == '/')) {
			tempc = c;
			preflag = 1;
			continue;
		}
		if(preflag && (c=='*')) {
			inmemo  = 1;
			preflag = 0;
			continue;
		} else if((preflag) && (!inmemo)) {
			preflag = 0;
			putchar(tempc);
		}

		if(inmemo && (c == '*')) {
			endflag = 1;
			continue;
		}
		if(endflag && (c == '/')) {
			endflag = 0;
			inmemo = 0;
			continue;
		} else if (inmemo && endflag)
			endflag = 0;
		
		if(!inmemo) {
			putchar(c);
			preflag = 0;
			endflag = 0;
		}
	}
	return(0);
}

int
main(void) {
	
	delmem();
}
