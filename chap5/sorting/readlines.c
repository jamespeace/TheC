
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000		/* max length of any input line */

int getline(char *, int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getlines(line, MAXLEN)) > 0)
		if (nlines > MAXLEN || (p = malloc(len * sizeof(char))) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
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
