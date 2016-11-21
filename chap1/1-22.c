/* use two arrays to deal with the problem.
 * next (a basic unit of the FOLDLENGTH)is the key of this program.
 * 將 foldength視為一個處理單位，若是一個單位內全無空格，視為處理完。
 * 若有空格，則next = location - spaceholder.表示已經處理的字元數目，
 * 等到next 滿了，在處理一次
 * 2016/10/19 15:50  手痛之下終於解決這個問題！
 * */
#include<stdio.h>
#define MAX 100

typedef struct _node *pnode;

struct _node{
	char value[MAX];
	pnode next;
}node;

pnode head, tail;

void
int main(void)
{
	int n, i, p;
	char s[MAX];
	n = i = p = 0;
	printf("The length of one line ?");
	scanf("%d", &n);
	
	if(n < MAX)
		while((c=getchar()) != EOF || c != '\n') 
		{
			while(i < n) 
			{
				if(c == '\t' || c == ' ')				
			}
		}
	else
		printf("ERROR!the length is too long");

	return 0;
}


