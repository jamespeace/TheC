#include <stdio.h>
#define MAXLINE 1000

int main(void)
{
	double sum, atoff(char []);
	char line[MAXLINE];
	int getline(char [], int);
	
	sum = 0;
	while (getline(line, MAXLINE) > 0) 
		printf("\t%g\n", sum += atoff(line));
	return 0;	
}
