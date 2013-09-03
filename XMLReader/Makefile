#
# makefile
#

# which c plus plus compiler
CPP     = ccache g++

# options for compiler
CFLAGS  = 
#-Wall -Werror

# is debug? (for development)
CDEBUG  = -g -Wno-unknown-pragmas -Wno-format

# objects
OBJS	= main.o xml_parser.o tinystr.o tinyxmlerror.o tinyxml.o tinyxmlparser.o

# binary
BIN	    = main 

# rock..
all: clean $(BIN)

# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~
