#include <stdio.h>

/* strcats concatenate t to end of s; s must be big enough */
void strcats(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

int main(void)
{
	char s[20] = "Hello ";
	char t[] = "World!";
	strcats(s, t);
	printf("%s\n", s);
	return 0;
}
