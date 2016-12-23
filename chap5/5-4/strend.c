#include <stdio.h>
#include <string.h>
int strend(char [], char[]);

int main(void)
{
	char s[10] = "this is";
	char t[10] = "is ";

	printf("%d\n", strend(s, t));
	return 0;
}

int strend(char *s, char *t)
{
	s += strlen(s) - strlen(t); 
	if(strlen(s) < strlen(t))
		return -1;
	while ((*(s++) == *(t++)))
		;
	if (*t)
		return 0;
	return 1;
}
