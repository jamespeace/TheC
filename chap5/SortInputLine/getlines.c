#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getlines(char *s, int maxlen)
{
	int c, i;
	for (i = 0; --maxlen > 0 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
