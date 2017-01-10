struct nlist {
	struct nlist *next;		/* next entry in chain */
	char *name;				/* defined name */
	char *defn;				/* replacement text */
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];	/* pointer table */
