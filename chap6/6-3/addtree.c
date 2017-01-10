#include <stdio.h>
#include <string.h>
#include "tnode.h"

struct tnode *talloc(void);
struct lcount *lalloc(void);
char *strsdup(char *);

/* addtree:  add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int line)
{
	int cond;
	struct lcount *q, *r;
	q = r = NULL;

	if (p == NULL) {		/* a new word has arrived */
		p = talloc();		/* make a new node */
		p->word= strsdup(w);
		p->lptr = lalloc();
		p->lptr->line = line;
		p->lptr->count = 1;
		p->lptr->next = NULL;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		q = p->lptr;
		while (q != NULL)
			if (q->line == line) {
				q->count++;
				break;
			} else {
				r = q;
				q = q->next;
			}
		if (q == NULL) {
			r->next = lalloc();
			r = r->next;
			r->line = line;
			r->count = 1;
			r->next = NULL;
		}
	} else if (cond < 0)		/* less than into left subtree */
		p->left = addtree(p->left, w, line);
	else 
		p->right = addtree(p->right, w, line);
	return p;
}
