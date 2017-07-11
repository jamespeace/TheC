#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STRCON 1234
#define COMMENT 1111

/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
	int c;
	int getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	*w = c;
	if (c == EOF)
		return c;
	while (!isspace(*++w = c = getch()) && c != EOF)
		;
	ungetch(c);
	*w = '\0';
	return word[0];
}

