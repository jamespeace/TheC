#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;

char getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("error: stack buf full\n");
}

void ungets(const char s[])
{
	size_t i = strlen(s);
	while (i > 0)
		ungetch(s[--i]);
}

int main(void)
{
	char c, *s = "hello, world.";

	ungets(s);
	while ((c = getch()) != EOF)
		putchar(c);
	return 0;
}
