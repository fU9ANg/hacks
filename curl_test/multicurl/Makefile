
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

# flags of buildhouse
BHFLAGS	= 
#-D_BUILD_HOUSE_GMAE

# is debug? (for development)
CDEBUG  = -g -DDEBUG

# macro
CMACRO	= 
#-D_OLD_MAKEHOUSE_GAME

# objects
OBJS    = 	main.o \
			Single.o \
			net_curl.o \
			task_curl.o

# binary
BIN	    = a.out

# where are include files kept
INC	    = -I. -I./includes -I./handler -I./content -I./handler/task

# for Linker
LINK        = -lev -lpthread -lcurl
# rock..
all: $(BIN)

# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(CMACRO) -o $@ $(OBJS) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~ logs .lock
