CC = gcc
CFLAGS = -g -Wall
OBJS = main.c addtree.c talloc.c strsdup.c getword.c getch.c treeprint.c\
	   lalloc.c treefree.c linefree.c 

all: count

count: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
clean:
	$(RM) count

run: count
	./count < file 
