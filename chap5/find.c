#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);
/* find:  print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (getlines(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
	return found;
}

int getlines(char line[], int maxline)
{
	int c, i;

	for (i = 0;i < maxline - 1 && (c = getchar()) != '\n' && c != '\t'; i++) 
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	line[i++] = '\0';
	return i;
}
