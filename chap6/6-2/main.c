#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
int main(int argc, char *argv[])
{
	struct tnode *root = NULL;
	char word[MAXWORD];
	int n;

	if (argc > 2) {
		perror("Usage: count number \n");
		exit(1);
	}
	
	n = (argc == 1) ? 6 : atoi(*(argv+1));

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]))
			root = addtree(root, word, n);
	}
	treeprint(root);
	return 0;

}
