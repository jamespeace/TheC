CC = gcc
CFLAGS = -g -Wall
OBJS = main.c hash.c printhash.c getword.c strsdup.c getch.c freehash.c
all: lookup
lookup: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS)

run: lookup
	./lookup < test
.PHONY: clean
clean:
	$(RM) lookup
