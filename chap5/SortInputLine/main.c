#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000	/* max #lines to be sorted */
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsorts(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int strcmp_wrapper(void * s1, void *s2) {
	return strcmp((char*)s1, (char*)s2);
}
int numcmp_wrapper(void *s1, void *s2) {
	return numcmp((char *)s1, (char *)s2);
}
int main(int argc, char *argv[])
{
	int nlines;			/* number of input lines read */
	int numeric = 0;			/* 1 if numeric sort */

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsorts((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp: strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
	return 0;
}

