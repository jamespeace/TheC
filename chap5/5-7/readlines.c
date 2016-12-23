#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000		/* max length of any input line */
#define MAXSTORE 10000
int getlines(char *, int);

/* readlines:  read input lines */
int readlines(char *lineptr[], char *linestore, int maxlines)
{
	int len, nlines;
	char *p, *origin, line[MAXLEN];

	nlines = 0;
	while ((len = getlines(line, MAXLEN)) > 0)
		if (nlines > MAXLEN || p + len < MAXSTORE + origin - 1)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}

/*	writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	while (nlines--)
		printf("%s\n", *lineptr++);
}
