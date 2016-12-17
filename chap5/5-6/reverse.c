#include <stdio.h>
#include <string.h>

void reverse(char *);

int main(void)
{
	char s[20] = "Hello World!";

	reverse(s);
	printf("%s\n", s);
	return 0;
}

void reverse(char *s)
{
	char temp, *t;

	for (t = s + (strlen(s) - 1); s < t; s++, t--) {
		temp = *s;
		*s = *t;
		*t = temp;
	}
}
