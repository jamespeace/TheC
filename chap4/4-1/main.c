#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int lim);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
	char line[MAXLINE];
	int i;
	
	while (getline(line, MAXLINE) > 0) {
		printf("%s", line);
		if ((i = strrindex(line, pattern)) >= 0) 
			printf("%d\n", i);	
	}
	return 0;	
}
