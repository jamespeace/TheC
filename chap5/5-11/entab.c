/* I don't know how to code.
 * Remain to tomorrow.
 * 2016/12/25 13:46
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c, tabinc, argcount = --argc;
	char **argvector = ++argv;

	if (argcount > 0)
		tabinc = (*argvector)[0] - '0';
	else
		tabinc = 8;
	for (i = 0; (c = getchar()) ! = EOF; i++) {
		if (i > tabinc) {
			n = (--argcount > 0) ?(*++argvector)[0] - '0' : 8;
			i = 1;
		}

		if (c == '\t') {
			
		}
	}
}
