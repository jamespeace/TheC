#include <stdio.h>

int getline(char s[], int lim)
{
	int i;
	char c;
	
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') 
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
