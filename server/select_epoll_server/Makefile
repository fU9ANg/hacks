
#
# makefile
#

# which c plus plus compiler
CPP     = ccache g++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror

# is debug? (for development)
CDEBUG  = -g

# objects
SELECTOBJS  = selectServer.o
EPOLLOBJS   = epollServer.o 
POLLOBJS    = pollServer.o
CLIENTOBJS  = client.o 
OBJS        = $(SELECTOBJS) $(POLLOBJS) $(EPOLLOBJS) $(CLIENTOBJS)

# binary
BIN	        = selectServer epollServer pollServer client 

# where are include files kept
INC	        = -I.

# rock..
all:$(BIN)

# how to compiling programs
all:$(BIN)

selectServer:$(SELECTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(SELECTOBJS) 
pollServer:$(POLLOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(POLLOBJS) 
epollServer:$(EPOLLOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EPOLLOBJS) 
client:$(CLIENTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(CLIENTOBJS)

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~
