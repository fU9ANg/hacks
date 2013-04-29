
#
# makefile for chatServer
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
OBJS    = handler.o main.o socket.o utils.o

# binary
BIN	    = chatServer

# where are include files kept
INC	    = -I. -I./includes -I./handler -I./content

# for Linker
LINK        = -lpthread
# rock..
all:$(BIN)

# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~
