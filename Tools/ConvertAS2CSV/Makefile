
#
# Makefile
#
# by fU9ANg
# 2013
#
# convert as (flash script to csv file)
#

# Which C++ compiler
CXX         = ccache g++

# Binary
BIN         = ConvertAS2CSV

# Objects
OBJS        = src/as2csv.o

CXXFLAGS    = -Wall -Werror -g
INCLUDES    = -I. -I./src
LIB_PATH    = -L.

all:$(BIN)
$(BIN):$(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIB_PATH)

%.o:$.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<


.PHONY: clean
clean:
	-rm -rf $(OBJS) $(BIN) *~
