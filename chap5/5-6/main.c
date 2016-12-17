#include <stdio.h>
#include <string.h>

#define MAX 100

int getlines(char *line, int max);
int strindex(char *s, char *t);

int main(void)
{
	char line[MAX];
	char s[MAX] = "ould";
	while (getlines(line, MAX) >= 0) {
		if (strindex(line, s) >= 0) {
			printf("%s", line);
		}
	}
	return 0;
}

int getlines(char *s, int max)
{
	char *i = s;
	while (--max > 0 && (*i++ = getchar()) != '\n')
		;
	*i = '\0';
	return i - s;
}

int strindex2(char *s, char *t)
{
	char *i, *j, *k;

	for (i = s; *i != '\0'; i++) {
		for (j = i, k = t; *j == *k; j++, k++)
			;
		if (k > t && *k == '\0')
			return i - s;
	}
	return -1;
}

