#
# makefile
#

# which c plus plus compiler
CPP     = ccache c++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror -fPIC

# is debug? (for development)
CDEBUG  = -g -D_DEBUG_FUNCTION_

# objects
OBJS    = main.o


# binary
BIN	    = debug_test

# where are include files kept
INC	    = -I.

# for Linker
LINK    = -lpthread -lrt
# rock..

all: clean $(BIN)

# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o $(BIN) *~
