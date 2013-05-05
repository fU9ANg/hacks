
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
EXAMPLE01OBJS	= Example01.o
EXAMPLE02OBJS	= Example02.o
EXAMPLE03OBJS	= Example03.o
EXAMPLE04OBJS	= Example04.o
EXAMPLE05OBJS	= Example05.o
EXAMPLE06OBJS	= Example06.o
EXAMPLE07OBJS	= Example07.o
EXAMPLE08OBJS	= Example08.o
EXAMPLE09OBJS	= Example09.o
EXAMPLE10OBJS	= Example10.o
EXAMPLE11OBJS	= Example11.o
EXAMPLE12OBJS	= Example12.o
EXAMPLE13OBJS	= Example13.o
EXAMPLE14OBJS	= Example14.o
EXAMPLE15OBJS	= Example15.o
EXAMPLE16OBJS	= Example16.o
EXAMPLE17OBJS	= Example17.o
EXAMPLE18OBJS	= Example18.o
EXAMPLE19OBJS	= Example19.o

OBJS        = $(EXAMPLE01OBJS) \
			  $(EXAMPLE02OBJS) \
			  $(EXAMPLE03OBJS) \
			  $(EXAMPLE04OBJS) \
			  $(EXAMPLE05OBJS) \
			  $(EXAMPLE06OBJS) \
			  $(EXAMPLE07OBJS) \
			  $(EXAMPLE08OBJS) \
			  $(EXAMPLE09OBJS) \
			  $(EXAMPLE10OBJS) \
			  $(EXAMPLE11OBJS) \
			  $(EXAMPLE12OBJS) \
			  $(EXAMPLE13OBJS) \
			  $(EXAMPLE14OBJS) \
			  $(EXAMPLE15OBJS) \
			  $(EXAMPLE16OBJS) \
			  $(EXAMPLE17OBJS) \
			  $(EXAMPLE18OBJS) \
			  $(EXAMPLE19OBJS)

# binary
BIN	        = Example01 Example02 \
			  Example03 Example04 \
			  Example05 Example06 \
			  Example07 Example08 \
			  Example09 Example10 \
			  Example11 Example12 \
			  Example13 Example14 \
			  Example15 Example16 \
			  Example17 Example18 \
			  Example19

# where are include files kept
INC	        = -I.

# rock..
all:$(BIN)

# how to compiling programs
all:$(BIN)

Example01:$(EXAMPLE01OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE01OBJS) 
Example02:$(EXAMPLE02OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE02OBJS) 
Example03:$(EXAMPLE03OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE03OBJS) 
Example04:$(EXAMPLE04OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE04OBJS) 
Example05:$(EXAMPLE05OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE05OBJS) 
Example06:$(EXAMPLE06OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE06OBJS) 
Example07:$(EXAMPLE07OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE07OBJS) 
Example08:$(EXAMPLE08OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE08OBJS) 
Example09:$(EXAMPLE09OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE09OBJS) 
Example10:$(EXAMPLE10OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE10OBJS) 
Example11:$(EXAMPLE11OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE11OBJS) 
Example12:$(EXAMPLE12OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE12OBJS) 
Example13:$(EXAMPLE13OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE13OBJS) 
Example14:$(EXAMPLE14OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE14OBJS) 
Example15:$(EXAMPLE15OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE15OBJS) 
Example16:$(EXAMPLE16OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE16OBJS) 
Example17:$(EXAMPLE17OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE17OBJS) 
Example18:$(EXAMPLE18OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE18OBJS) 
Example19:$(EXAMPLE19OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(EXAMPLE19OBJS) 

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) example.txt *~
