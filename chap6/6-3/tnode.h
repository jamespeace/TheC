struct lcount {
	int line;
	int count;
	struct lcount *next;
};

struct tnode {
	char *word;
	struct tnode *left;
	struct tnode *right;
	struct lcount *lptr;
};
