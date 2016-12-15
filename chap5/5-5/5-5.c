#include <stdio.h>
#include <string.h>
char *strncpys(char*, char*, int);
char *strncats(char*, char*, int);
char *strncmps(char*, char*, int);

int main(void)
{
	char s[20] = "Hello ";
	char t[10] = "Whrld!";
	printf("%s\n", strncpys(s, t, 2));
	return 0;
}

char *strncpys(char *s, char *t, int n)
{
	int i, len = strlen(s);
	if (strlen(t) < n)
		return s;
	for(i = 0; i < n; i++)
		*(s + len+ i) = *(t + i);
	*(s + len + i) = '\0';
	return s;
}
