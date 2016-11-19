/*
 * Write the function htoi(s), which converts a 
 * string of hexa-decimal digits (including an 
 * optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a
 * through f, and A through F.
 *
 */
#include<stdio.h>
#define MAX 100

int htoi(char *s);

int main(void) 
{
	int i;
	char *test[]  =
		  {
			  "F00",
			  "bar",
			  "0100",
			  "0x1",
			  "0XA",
			  "0X0C0BE",
			  "abcdef",
			  "123456",
			  "0x123456",
			  "deadbeef",
			  "zog_c"
		  };
	for(i = 0; i < 11; i++)
		printf("hex = %s ,  decimal = %d\n",test[i], htoi(test[i]));
	return 0;
}

int htoi(char *hex_str)
{
	char c;
	int i, decimal;
	i = 0;
	decimal = 0;
	if(hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		i = 2;
	while((c = hex_str[i++]) != '\0') {
		if(c <= 'f' && 'a' <= c)
			decimal = decimal * 10 + c - 'a';
		else if(c <= 'F' && 'A' <= c)
			decimal = decimal * 10 + c - 'A';
		else if('0' <= c && c <= '9')		
			decimal = decimal * 10 + c - '0';
		else
			return -1;
	}
	return decimal;
}

