cmake_minimum_required (VERSION 2.8)
project ("server of [select, poll, epoll]")

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
SET (SELECTSERVER_LIST 
    ./selectServer.c
)
SET (POLLSERVER_LIST 
    ./pollServer.c
)
SET (EPOLLSERVER_LIST 
    ./epollServer.c
)
SET (CLIENT_LIST 
    ./client.c
)

# libraries for linker
SET (EXTRA_LIBS 
    -lpthread -lrt 
)

# how to compiling programs
add_executable (client ${CLIENT_LIST})
target_link_libraries (client ${EXTRA_LIBS})

add_executable (pollServer ${POLLSERVER_LIST})
add_executable (epollServer ${EPOLLSERVER_LIST})
add_executable (selectServer ${SELECTSERVER_LIST})
