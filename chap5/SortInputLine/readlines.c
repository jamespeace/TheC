#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXLEN 1000 /* max length of any input line */
int getlines(char *, int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getlines(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = (char*)malloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}


