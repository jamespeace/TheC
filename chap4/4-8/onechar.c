#include <stdio.h>

int buf[1];
int bufp = 0;

char getch(void)
{
	return (bufp == 0) ? getchar() : buf[--bufp];
}

void ungetch(char c)
{
	if (bufp == 1)
		printf("error: buf full\n");
	else
		buf[bufp++] = c;
}

int main(void)
{
	int c;

	while ((c = getch()) != EOF) {
		if (c == '/') {
			putchar(c);
			if ((c = getch()) == '*') {
				ungetch('!');
			}
		}
		putchar(c);
	}
	return 0;
}

