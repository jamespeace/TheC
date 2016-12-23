#include <stdio.h>

int getlines(char *line, int maxlens)
{
	int c, i = 0;		/* c is assigned to integer. */
	while ((i < maxlens - 1) && 
		  ((c = getchar()) != EOF) && 
		   (c != '\n')) {	/* expression: i < maxlens - 1. */
		line[i++] = c;
	}
	if (c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
		return i;
}
