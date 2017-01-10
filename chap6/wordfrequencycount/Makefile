CC =gcc 
CFLAGS = -g -Wall
all: maketree
OBJS = main.c addtree.c strdup.c talloc.c getword.c treeprint.c getch.c
maketree: $(OBJS) tnode.h
	$(CC) $(CFLAGS) -o $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) maketree
