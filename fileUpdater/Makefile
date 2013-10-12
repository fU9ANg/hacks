#
# makefile
#

# set src, dst directory and flags for protobuf
PROTOC      = protoc
PBFLAGS     = --cpp_out
PBSRC       = ./protocol
PBDST       = ./

# which c plus plus compiler
CPP     = ccache g++

# options for compiler
CFLAGS  = -Wall -Werror

INC		= -I. -I./protocol

# is debug? (for development)
CDEBUG  = -g -Wno-unknown-pragmas -Wno-format

COMMOBJS= utils.o tinystr.o tinyxmlerror.o tinyxml.o tinyxmlparser.o

PROTOBJS= protocol/updater.pb.o

# server cpp temp objects
SRVOBJS = server.o

# client cpp temp objects
CLIOBJS = client.o

# compiling objects
OBJS    = $(SRVOBJS) $(CLIOBJS) $(COMMOBJS) $(PROTOBJS)

# binary
BIN	    = server client

# libraries
LIBS	= -lcurl -lprotobuf

# rock..
all: clean precompile_protobuf $(BIN)

precompile_protobuf:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/updater.proto

# how to compiling programs
server:$(SRVOBJS) $(COMMOBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(SRVOBJS) $(COMMOBJS) $(PROTOBJS) $(LINK) $(LIBS)
client:$(CLIOBJS) $(COMMOBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(CLIOBJS) $(COMMOBJS) $(PROTOBJS) $(LINK) $(LIBS)

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) ./*.o protocol/*.cc protocol/*.h *~
