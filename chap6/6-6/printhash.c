#include "table.h"
#include <stdio.h>
#include <stdlib.h>

void printhash(struct nlist **p, int len)
{
	int i;
	struct nlist *q;

	for (i = 0; i < len; i++) {
		q = *p;
		while (q != NULL) {
			printf("name: %s, defn: %s\n", q->name, q->defn);
			q = q->next;
		}
		p++;
	}
}

