#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];

int getch(void)
{
	return (buf > 0) ? getchar() : buf[--bufp];
}

void ungetch(int c)
{
	if (bufp > BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bup++] = c;
}
