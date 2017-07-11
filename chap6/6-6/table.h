struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101
#define MAXWORD 100


