
# makefile for cmake

cmake_minimum_required (VERSION 2.8)
project (server)
project (client)

# options for compiler
SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -g -ggdb -D_ENABLED_SSL")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb -D_ENABLED_SSL")
#SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -g -ggdb")
#SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")

# is debug?
SET (CMAKE_BUILD_TYPE Debug)

# which c plus plus compiler
SET (CMAKE_CXX_COMPILER "ccache")
SET (CMAKE_CXX_COMPILER_ARG1 "g++")

# which c compiler
SET (CMAKE_C_COMPILER "ccache")
SET (CMAKE_C_COMPILER_ARG1 "gcc")

# directory for includes
INCLUDE_DIRECTORIES (
    ./
)

# source code list for server file
SET (SERVER_SRC_LIST
    client.cc
    utils.cc
)

# source code list for client file
SET (CLIENT_SRC_LIST
    server.cc
    utils.cc
)

# set libraries directory
SET (LIBS_DIRS
    ./
    /usr/local/ssl/lib
    /usr/ssl/lib
)

# libraries for linker
SET (EXTRA_LIBS 
    -lssl -lcrypto -ldl
)

# how to compiling programs
add_executable (server ${SERVER_SRC_LIST})
target_link_libraries (server ${EXTRA_LIBS})

add_executable (client ${CLIENT_SRC_LIST})
target_link_libraries (client ${EXTRA_LIBS})
