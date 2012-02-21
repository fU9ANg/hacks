#include <stdio.h>

main()
{
	char c='\c';	/* warning: unknown escape sequence '\c' */
	printf ("%d\n", c);
}
