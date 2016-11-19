#include<stdio.h>
#include<string.h>
int main(void)
{
	char str1[8] = "World!";
	char str2[8] = "Hello~";
	char str3[4];
	char   *p = str3;
	int i;
	
	strcpy(str3, "jameswinnnnnnnnnnn");
	printf("str1: %p\nstr2: %p\nstr3: %p\n", str1, str2, str3);
	for(i = 0; i < 48; i++) {
		printf("%c ", *(p + i));
		if(*(p + i) == '\0')	
			printf("*");
		else					
			printf(" ");
		printf("\n");
	}
	return 0;
}
