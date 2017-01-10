#include <stdio.h>
#include "tnode.h"
/* treeprint:  in-order print of tree p */
void treeprint(struct tnode *p)
{
	struct lcount *q = NULL;

	if (p != NULL) {
		q = p->lptr;
		if (p->left != NULL)
			treeprint(p->left);
		printf("%10s\n", p->word);
		while (q != NULL) {
			printf("          %4d  %5d\n", q->line ,q->count);
			q = q->next;
		}
		if (p->right != NULL)
			treeprint(p->right);
	}
}
