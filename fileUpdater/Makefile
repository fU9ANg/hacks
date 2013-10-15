#
# makefile
#

# set src, dst directory and flags for protobuf
PROTOC      = protoc
PBFLAGS     = --cpp_out
PBSRC       = ./protocol
PBDST       = ./

# which c compiler
CPP     = ccache gcc

# which c plus plus compiler
CPP     = ccache g++

# options for compiler
CFLAGS  = -Wall -Werror

INC		= -I. -I./protocol

# is debug? (for development)
CDEBUG  = -g -Wno-unknown-pragmas -Wno-format

COMMOBJS= utils.o tinystr.o tinyxmlerror.o tinyxml.o tinyxmlparser.o md5_calc.o curl_down.o

PROTOBJS= protocol/updater.pb.o

# read dir temp object
RDOBJS  = readdir.o

# create update xml object
CUXOBJS = createupdatexml.o

# download file object
DLFOBJS = downloadfile.o

# server cpp temp object
SRVOBJS = server.o

# client cpp temp object
CLIOBJS = client.o

# compiling objects
OBJS    = $(SRVOBJS) $(CLIOBJS) $(COMMOBJS) $(PROTOBJS) $(RDOBJS) $(CUXOBJS) $(DLFOBJS)

# binary
BIN	    = server client createupdatexml downloadfile readdir 

# libraries
LIBS	= -lcurl -lprotobuf -lcrypto -lssl

# rock..
all: clean precompile_protobuf $(BIN)

precompile_protobuf:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/updater.proto

# how to compiling programs
server:$(SRVOBJS) $(COMMOBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(SRVOBJS) $(COMMOBJS) $(PROTOBJS) $(LINK) $(LIBS)
client:$(CLIOBJS) $(COMMOBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(CLIOBJS) $(COMMOBJS) $(PROTOBJS) $(LINK) $(LIBS)

readdir:$(RDOBJS) $(COMMOBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(RDOBJS)  $(COMMOBJS) $(PROTOBJS) $(LINK) $(LIBS)
createupdatexml:$(CUXOBJS) $(COMMOBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(CUXOBJS) $(COMMOBJS) $(PROTOBJS) $(LINK) $(LIBS)
downloadfile:$(DLFOBJS) $(COMMOBJS) $(PROTOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(DLFOBJS) $(COMMOBJS) $(PROTOBJS) $(LINK) $(LIBS)

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) ./*.o protocol/*.cc protocol/*.h *~ ./xml/*.xml *.xml
