#
# makefile
#

# which c plus plus compiler
CPP       = ccache g++

# which c compiler
CC        = ccache cc

# options for compiler
CFLAGS    = -Wall -Werror

# is debug? (for development)
CDEBUG    = -g -DDEBUG

# macro
CMACRO	  = 

# objects
OBJS      = SheetBase.o \
			Sheet.o \
			Test.o

# tools objects
TOOLSOBJS = pugixml/pugixml.o \
		  	ExcelData.o \
		  	Tools.o

# binary
BIN	      = TestSheet
TOOLSBIN  = Tools

# where are include files kept
INC	      = -I. -I./pugixml

# for Linker
LINK      =

# rock..
all	: $(TOOLSBIN) $(BIN)


# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(CMACRO) -o $@ $(OBJS) $(LINK)
$(TOOLSBIN):$(TOOLSOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(CMACRO) -o $@ $(TOOLSOBJS) $(LINK)

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(TOOLSOBJS) $(OBJS) $(BIN) $(TOOLSBIN) *~ logs .lock
