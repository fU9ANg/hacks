
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
UPLOADOBJS  = upload_file.o
DOWNLOADOBJS= download_file.o 
OBJS        = $(UPLOADOBJS) $(DOWNLOADOBJS)

# binary
BIN	        = upfile downfile

INC	        = -I.

LINK		= -lcurl

# how to compiling programs
all:$(BIN)

upfile:$(UPLOADOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(UPLOADOBJS) $(LINK)
downfile:$(DOWNLOADOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(DOWNLOADOBJS) $(LINK)

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~
