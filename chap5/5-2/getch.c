#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int i)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = i;
	else
		printf("error: buf full\n");
}
