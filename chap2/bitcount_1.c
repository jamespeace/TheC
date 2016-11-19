#include<stdio.h>

int bitcount(unsigned x)
{
	int b = 0;
	for(b = 0; x != 0; x &= (x-1))
		b++;
	return b;
}

int getint(void)
{
	char c;
	int sum = 0;
	while((c = getchar()) != EOF) {
		if(('0' <= c) && (c <= '9')) {
			sum *= 10;
			sum += (c - '0');
		}else 
			return sum;
	}
}

int main(void)
{
	int x;

	printf("Input a unsigned number:");
	
	printf("%d\n", 

	return 0;
}
