#
# Makefile for chap 3 of BLP
#

CC          =    gcc
CFLAGS      =   -Wall -Werror
#CFLAGS      =
DEBUG       =   -g
INCLUDES    =   -I.
LIBRARYS    =   -L.
BIN         =   menu1 menu2 menu3 sizeterm
all:$(BIN)

menu1:menu1.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
menu2:menu2.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
menu3:menu3.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
sizeterm:sizeterm.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

%.o:%.c
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o *~ $(BIN) 
