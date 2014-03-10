#
# makefile
#

# which c plus plus compiler
CPP     = ccache g++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = 
#-Wall -Werror

# is debug? (for development)
CDEBUG  = -g

# objects
OBJS        = fud.o main.o

# binary
BIN	        = fud

INC	        = -I.

LINK		= -lcurl

# how to compiling programs
all:$(BIN)

fud:$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS) $(LINK)

%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~
