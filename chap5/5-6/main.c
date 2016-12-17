#include <stdio.h>
#include <string.h>

#define MAX 100

int getlines(int *line, int max);
int strindex(int *source, int *t);

int main(void)
{
	int line[MAX];
	char s[MAX] = "ould";
	while (getlines(line, MAX) >= 0) {
		if (strindex(line, s) >= 0) {
			printf("%s", line);
		}
	}
	return 0;
}

int getlines(int *s, int max)
{
	int *i = s;
	while (--max > 0 && (*i++ = getint()) != '\n')
		;
	*i = '\0';
	return i - s;
}

int strindex2(int *s, int *t)
{
	int *i, *j, *k;

	for (i = s; *i != '\0'; i++) {
		for (j = i, k = t; *j == *k; j++, k++)
			;
		if (k > t && *k == '\0')
			return i - s;
	}
	return -1;
}
