
# makefile for cmake

cmake_minimum_required (VERSION 2.8)
project (upfile)
project (downfile)

# options for compiler
SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -g -ggdb")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
# is debug?

SET (CMAKE_BUILD_TYPE Debug )

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

# source code list for up-load file
SET (UP_SRC_LIST
    ./upload_file.cc
)

# source code list for down-load file
SET (DOWN_SRC_LIST
    ./download_file.cc
)

# libraries for linker
SET (EXTRA_LIBS 
    -lcurl
)

# how to compiling programs
add_executable (upfile ${UP_SRC_LIST})
target_link_libraries (upfile ${EXTRA_LIBS})

add_executable (downfile ${DOWN_SRC_LIST})
target_link_libraries (downfile ${EXTRA_LIBS})
