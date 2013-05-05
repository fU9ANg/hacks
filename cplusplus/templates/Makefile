
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
EXAMPLE01OBJS	= Example01.o
EXAMPLE02OBJS	= Example02.o
EXAMPLE03OBJS	= Example03.o

OBJS        = $(EXAMPLE01OBJS) \
			  $(EXAMPLE02OBJS) \
			  $(EXAMPLE03OBJS)

# binary
BIN	        = Example01 Example02 Example03

# where are include files kept
INC	        = -I.

# rock..
all:$(BIN)

# how to compiling programs
all:$(BIN)

Example01:$(EXAMPLE01OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE01OBJS) 
Example02:$(EXAMPLE02OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE02OBJS) 
Example03:$(EXAMPLE03OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE03OBJS) 

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) example.txt *~
