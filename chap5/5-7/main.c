#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max #lines to be sorted */
#define MAXSTORE 10000		/* max space allocated for all lines.	Same as ALLOCSIZE on p.91 */
char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], char *linestore, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void)
{
	int nlines;		/* number of input lines read */
	char linestore[MAXSTORE];
	if ((nlines = readlines(lineptr, linestore, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
