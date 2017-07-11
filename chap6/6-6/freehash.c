#include <stdlib.h>
#include "table.h"
#include <stdio.h>

void freehash(struct nlist **p, int len)
{
	int i;
	struct nlist *q, *r;

	for (i = 0; i < len; i++) {
		r = q = *p;
		while (r != NULL) {
			q = r;
			r = r->next;
			free(q);
		}
		p++;
	}
}
