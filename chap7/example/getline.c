#include <stdio.h>

/* getline: read a file, return length */
int getlines(char *line, int max)
{
	if (fgetss(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}
