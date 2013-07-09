#
# Makefile
#

CC          =    g++
CXXFLAGS    =   -Wall -Werror
DEBUG       =   -g -D_ENABLED_SSL
#DEBUG       =   -g
INCLUDES    =   -I.
LIBRARYS    =   -L. -L/usr/local/ssl/lib -L/usr/ssl/lib
BIN			=	 server client
LINK		=   -lssl -lcrypto -ldl

SERVEROBJS	=    server.o utils.o
CLIENTOBJS  =    client.o utils.o

all:$(BIN)

server:$(SERVEROBJS)
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $(SERVEROBJS) $(LIBRARYS) $(LINK)
client:$(CLIENTOBJS)
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $(CLIENTOBJS) $(LIBRARYS) $(LINK)

%.o:%.cc
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o *~ $(BIN)
