#include <stdio.h>

int getlines(char *line, int maxlens)
{
	char c;
	int i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	if (c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (i < maxlens)
		return i;
	else 
		return -1;
}
