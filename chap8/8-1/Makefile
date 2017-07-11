CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_cat = -O0
CFLAGS_fcat = -O0

EXEC = fcat cat

SRCS_common = cat.c
all: $(EXEC)

fcat: fcat.c
	$(CC) $(CFLAGS_common) $(CFLAGS_fcat) \
		$@.c -o $@

unbuf_cat: cat.c unbuf_cat.c
	$(CC) $(CFLAGS_common) $(CFLAGS_cat) \
		-o $@ \
		$(SRCS_common) $@.c

buf_cat: $(SRCS_common) buf_cat.c
	$(CC) $(CFLAGS_common) $(CFLAGS_cat) \
		-DBUF -o $@ \
		$(SRCS_common) $@.c

run: buf_cat unbuf_cat fcat
	./unbuf_cat.exe test.txt > /dev/null
	./buf_cat.exe test.txt > /dev/null
	./fcat.exe test.txt > /dev/null
.PHONY:
	clean

clean:
	$(RM) cat.txt unbuf_cat.exe buf_cat.exe fcat.exe
