CC = gcc
CFLAGS = -g -Wall
OBJS = main.c addtree.c talloc.c strsdup.c getword.c getch.c treeprint.c

all: count

count: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
clean:
	$(RM) count

run: count
	./count 4 < test
