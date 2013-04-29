cmake_minimum_required (VERSION 2.8)
project (chatServer)

# options for compiler
SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -g -ggdb")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
# is debug?
SET (CMAKE_BUILD_TYPE Debug )

# which c plus plus compiler
#SET (CMAKE_CXX_COMPILER "clang")
SET (CMAKE_CXX_COMPILER "ccache")
SET (CMAKE_CXX_COMPILER_ARG1 "g++")

# which c compiler
#SET (CMAKE_C_COMPILER "clang")
SET (CMAKE_C_COMPILER "ccache")
SET (CMAKE_C_COMPILER_ARG1 "gcc")

# directory for includes
INCLUDE_DIRECTORIES (
    ./
)

# source code list
SET (SRC_LIST 
    ./main.cpp
    ./handler.cpp
    ./socket.cpp
    ./utils.cpp
)

# libraries for linker
SET (EXTRA_LIBS 
    -lpthread -lrt
)

# how to compiling programs
add_executable (chatServer ${SRC_LIST})
target_link_libraries (chatServer ${EXTRA_LIBS})
