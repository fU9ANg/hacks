#
# makefile of test for authServer
#

# which c plus plus compiler
CC          = ccache gcc

# options for compiler
CFLAGS      = -Wall -Werror

# is debug? (for development)
CDEBUG      = -g

# objects

SOCKETOBJS  = sock.o
SERVEROBJS  = authServer.o
CLIENTOBJS  = client.o 
OBJS        = $(SOCKETOBJS) $(SERVEROBJS) $(CLIENTOBJS)

# binary
BIN	        = authServer client

# where are include files kept
INC	        = -I.

# rock..
all: $(BIN)

authServer:$(SERVEROBJS) $(SOCKETOBJS)
	$(CC) $(CFLAGS) $(CDEBUG) -o $@ $(SERVEROBJS) $(SOCKETOBJS)
client:$(CLIENTOBJS) $(SOCKETOBJS)
	$(CC) $(CFLAGS) $(CDEBUG) -o $@ $(CLIENTOBJS) $(SOCKETOBJS)

%.o:%.c
	$(CC) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) ./message/proto *~
