/* if the number's next char is '-', turn to printf mode.
 * else i++;
 * In print mode , check s[i-1] .if it's '-' , don't print the s[i].
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void getlines(char *);			//getline from stdin.
void expend(char *, char *);	//expend s1 to s2.
int check(char *);				//check error in s1.
int main(void)
{
	char s1[10], s2[100];

	getlines(s1);
	printf("%s\n", s1);
	expend(s1, s2);
	printf("%s\n", s2);

	return 0;
}

void getlines(char s[])
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n') {
		if (c == '-' && i == 0)
			continue;	
		s[i++] = c;
	}
	if (s[i-1] == '-')
		i--;
	s[i] = '\0';
}

void expend(char s1[], char s2[]) 
{
	int i, j, k;
	i = j = 0;
	if (!check(s1)) {
		printf("ERROR! Check your Input!\n");
		exit(1);
	}
	while (i < strlen(s1)) {
		if (s1[i+1] == '-') {			//print mode
			if (i == 0) {				//first value
				for (k = s1[i]; k <= s1[i+2]; k++) {
					s2[j++] = k;
				}
			} else {					//in the middle.
				if (s1[i-1] == '-') {
					for (k = s1[i] + 1; k <= s1[i+2]; k++)
						s2[j++] = k;
				} else {
					for (k = s1[i]; k <= s1[i+2]; k++)
						s2[j++] = k;
				}
			}
			i += 2;
		} else 
			i++;	
	}
	s2[j] = '\0';
}

int check(char s[])
{
	int i;
	i = 0;
	while ( i < strlen(s) - 1) {
		if(s[i+1] == '-') {
			if ((isdigit(s[i]) && isdigit(s[i+2])) || 
				(isalpha(s[i]) && isalpha(s[i+2]))) 
				i += 2;
			else
				return 0;
		}
	}
	return 1;
}

