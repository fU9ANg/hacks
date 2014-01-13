
#
# makefile
#
#
# set src, dst directory and flags for protobuf
PROTOC      = protoc
PBFLAGS     = --cpp_out
PBSRC       = ./protocol
PBDST       = ./

# which c plus plus compiler
CPP     = ccache g++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror

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
    		Config.o \
    		SendTask.o \
		    database.o \
		    Evloop.o \
		    Sock.o \
		    Single.o \
		    ThreadPool.o \
		    RecvTask.o \
			AuthTask.o \
		    ProcessManager.o \
			handler/HandleMessage.o \
			handler/HandleUpdater.o \
			content/client.o \
			content/userlist.o

# protobuf objects
PROTOBJS= protocol/version.pb.o protocol/updatecontent.pb.o

# binary
BIN	    = server

# where are include files kept
INC	    = -I. -I./includes -I./handler -I./protocol -I./content

# for Linker
LINK    = libs/libev.a libs/libglog.a libs/liblua52.so libs/libmysqlcppconn.so -lprotobuf
#LINK   = -lev -lglog -lmysqlcppconn -llua5.2

# rock..
all: clean precompile_protobuf $(BIN)

precompile_protobuf:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/version.proto
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/updatecontent.proto

# how to compiling programs
$(BIN):$(OBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJS) $(PROTOBJS) $(LINK)
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~ logs .lock
