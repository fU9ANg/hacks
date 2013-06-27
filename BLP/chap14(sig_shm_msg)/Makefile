#
# Makefile for chap 14 of BLP
#

CC          =    gcc
#CFLAGS      =   -Wall -Werror
CFLAGS      =
DEBUG       =   -g
INCLUDES    =   -I.
LIBRARYS    =   -L.
BIN			=	shm_send shm_recv sem1 msg_send msg_recv 

all:$(BIN)

sem1:sem1.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

shm_send:shm_send.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
shm_recv:shm_recv.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

msg_send:msg_send.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
msg_recv:msg_recv.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

%.o:%.c
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o *~ $(BIN)
