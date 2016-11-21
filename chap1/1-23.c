#include<stdio.h>
#define MAX 100
int main(void)
{
	char c;
	while((c = getchar()) != EOF)
	{
		if(c == '/') {
			if((c = getchar()) == '/') { 
				while((c = getchar()) != '\n') ;
				putchar(c);
			}
			else if(c == '*') {
				while((c = getchar()) != '\n')
				{
					if(c == '*')
						if((c = getchar()) == '/')
							break;
				}
				if(c == '\n')
					putchar(c);
			}else
				printf("/%c", c);
		}else
			printf("%c", c);
	}
	return 0;
}
