
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
SELECTOBJS  = select_db.o
INSERTOBJS  = insert_db.o 
OBJS        = $(SELECTOBJS) $(INSERTOBJS)

# binary
BIN	        = select_db insert_db

# where are include files kept
INC	        = -I.

# rock..
all:$(BIN)

# how to compiling programs
all:$(BIN)

select_db:$(SELECTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(SELECTOBJS) 
insert_db:$(INSERTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(INSERTOBJS) 

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~
