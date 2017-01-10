#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *, int );
void treeprint(struct tnode *);
void treefree(struct tnode *);
int getword(char *, int);

/* word frequency count */
int main(void)
{
	struct tnode *root = NULL;
	char word[MAXWORD];
	int line_now = 1;

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]) && strcmp(word, "and") && strcmp(word, "the"))
			root = addtree(root, word, line_now);
		else if (word[0] == '\n')
			line_now++;
	}
	printf("      word  line  count\n");
	treeprint(root);
	treefree(root);
	return 0;

}
