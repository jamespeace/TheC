/*
 * for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 * 		s[i] = c;
 *
 * write a loop equivalent to the for loop above without using && and ||
 *
 * 																		*/
#include<stdio.h>
#define lim 100
int main(void)
{
	int i;
	char c, s[lim];
	i = 0;

	while((c=getchar()) != '\n') {
		if(!(i < lim - 1))
			break;
		else if(c == EOF)
			break;
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	printf("%s", s);

	return 0;
}
