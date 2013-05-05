cmake_minimum_required (VERSION 2.8)
project ("IO_tester")

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
SET (EXAMPLE01_LIST
        ./Example01.cpp
)

SET (EXAMPLE02_LIST
        ./Example02.cpp
)

SET (EXAMPLE03_LIST
        ./Example03.cpp
)

SET (EXAMPLE04_LIST
        ./Example04.cpp
)

SET (EXAMPLE05_LIST
        ./Example05.cpp
)

# libraries for linker
SET (EXTRA_LIBS 
    -lpthread -lrt 
)

# how to compiling programs
add_executable (Example01 ${EXAMPLE01_LIST})
target_link_libraries (Example01 ${EXTRA_LIBS})
add_executable (Example02 ${EXAMPLE02_LIST})
target_link_libraries (Example02 ${EXTRA_LIBS})
add_executable (Example03 ${EXAMPLE03_LIST})
target_link_libraries (Example03 ${EXTRA_LIBS})
add_executable (Example04 ${EXAMPLE04_LIST})
target_link_libraries (Example04 ${EXTRA_LIBS})
add_executable (Example05 ${EXAMPLE05_LIST})
target_link_libraries (Example05 ${EXTRA_LIBS})
