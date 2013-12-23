#
# makefile
#

# which c compiler
CPP     = ccache gcc

# which c plus plus compiler
CPP     = ccache g++

# options for compiler
CFLAGS  = 
#-Wall -Werror

INC		= -I.

# is debug? (for development)
CDEBUG  = -g -Wno-unknown-pragmas -Wno-format 
#-DDEBUG

COMMOBJS= tinystr.o tinyxmlerror.o tinyxml.o tinyxmlparser.o

# create update xml object
CUXOBJS = autoprotocol.o

# compiling objects
OBJS    = $(COMMOBJS) $(CUXOBJS)

# binary
BIN	    = autoprotocol

# libraries
LIBS	= -lpthread

# rock..
all: clean $(BIN)

# how to compiling programs
$(BIN):$(CUXOBJS) $(COMMOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(CUXOBJS) $(COMMOBJS) $(LINK) $(LIBS)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) ./*.o *~
