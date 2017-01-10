#include <string.h>
#include <stdio.h>
#include "tnode.h"

struct tnode *talloc(void);
char *strsdup(char *);

/* addtree:  add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond; 

	if (p == NULL) {		/* a new word has arrived */
		p = talloc();		/* make a new node */
		p->word = strsdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond  = strcmp(w, p->word)) == 0)
		p->count++;		/* repeat words */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else			/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}
