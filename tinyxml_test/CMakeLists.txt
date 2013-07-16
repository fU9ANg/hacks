
# makefile of cmake

cmake_minimum_required (VERSION 2.8)
project (tst_tinyxml)

# options for compiler
SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -Werror -g -Wno-unknown-pragmas -Wno-format")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb -Wno-unknown-pragmas -Wno-format")
# is debug?

SET (CMAKE_BUILD_TYPE Debug)

# which c plus plus compiler
#SET (CMAKE_CXX_COMPILER "clang") # apple clang compiler
SET (CMAKE_CXX_COMPILER "ccache")
SET (CMAKE_CXX_COMPILER_ARG1 "g++")

# which c compiler
#SET (CMAKE_C_COMPILER "clang")   # apple clang compiler
SET (CMAKE_C_COMPILER "ccache")
SET (CMAKE_C_COMPILER_ARG1 "gcc")

# directory for includes
INCLUDE_DIRECTORIES (
    ./
)

# source code list
SET (SRC_LIST
     main.cpp
     tinystr.cpp
     tinyxml.cpp
     tinyxmlerror.cpp
     tinyxmlparser.cpp
)

# libraries for linker
#SET (EXTRA_LIBS 
#    -lpthread -lrt
#)

# how to compiling programs
add_executable (tst_tinyxml ${SRC_LIST})
#target_link_libraries (server ${EXTRA_LIBS})
