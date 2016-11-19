#include<stdio.h>
#define MAX 100

void squeeze(char*, char*);
int main(void)
{
	char s[MAX] = "abcdef", c[MAX] = "ec";
	squeeze(s, c);
	printf("%s", s);

}

void squeeze(char s[], char c[])
{
	int i, j, k;		

	for(i = j = 0; s[i] != '\0'; i++)
	{
		for(k = 0; c[k] != '\0'; k++)
		{
			if(s[i] == c[k])
				break;
		}
		if(s[i] != c[k])
			s[j++] = s[i]; 
	}
	s[j] = '\0';
}

