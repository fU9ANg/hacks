#
# Makefile for chap 3 of BLP
#

CC          =    gcc
#CFLAGS      =   -Wall -Werror
CFLAGS      =
DEBUG       =   -g
INCLUDES    =   -I.
LIBRARYS    =   -L.
BIN			=	copy_block copy_stdio simple_open simple_read simple_write printdir1 printdir2 mmap

all:$(BIN)

copy_block:copy_block.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

copy_stdio:copy_stdio.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
simple_open:simple_open.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

simple_read:simple_read.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
simple_write:simple_write.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
printdir1:printdir1.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
printdir2:printdir2.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
mmap:mmap.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

%.o:%.c
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o *~ $(BIN) file.out
