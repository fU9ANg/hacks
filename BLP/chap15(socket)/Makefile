#
# Makefile for chap 15 of BLP
#

CC          =    gcc
CFLAGS      =   -Wall -Werror
DEBUG       =   -g
INCLUDES    =   -I.
LIBRARYS    =   -L.
BIN			= 	server1 client1 server2 client2 server3 client3 gethostname getdate getdate_udp server4 select server5

all:$(BIN)

server1:server1.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
client1:client1.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

server2:server2.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
client2:client2.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

server3:server3.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
client3:client3.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

server4:server4.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

gethostname:gethostname.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

getdate:getdate.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

getdate_udp:getdate_udp.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

select:select.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

server5:server5.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

%.o:%.c
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o *~ $(BIN) server_socket
