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
SET (EXAMPLE06_LIST
        ./Example06.cpp
)
SET (EXAMPLE07_LIST
        ./Example07.cpp
)
SET (EXAMPLE08_LIST
        ./Example08.cpp
)
SET (EXAMPLE09_LIST
        ./Example09.cpp
)
SET (EXAMPLE10_LIST
        ./Example10.cpp
)
SET (EXAMPLE11_LIST
        ./Example11.cpp
)
SET (EXAMPLE12_LIST
        ./Example12.cpp
)
SET (EXAMPLE13_LIST
        ./Example13.cpp
)
SET (EXAMPLE14_LIST
        ./Example14.cpp
)
SET (EXAMPLE15_LIST
        ./Example15.cpp
)
SET (EXAMPLE16_LIST
        ./Example16.cpp
)
SET (EXAMPLE17_LIST
        ./Example17.cpp
)
SET (EXAMPLE18_LIST
        ./Example18.cpp
)
SET (EXAMPLE19_LIST
        ./Example19.cpp
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
add_executable (Example06 ${EXAMPLE06_LIST})
target_link_libraries (Example06 ${EXTRA_LIBS})
add_executable (Example07 ${EXAMPLE07_LIST})
target_link_libraries (Example07 ${EXTRA_LIBS})
add_executable (Example08 ${EXAMPLE08_LIST})
target_link_libraries (Example08 ${EXTRA_LIBS})
add_executable (Example09 ${EXAMPLE09_LIST})
target_link_libraries (Example09 ${EXTRA_LIBS})
add_executable (Example10 ${EXAMPLE10_LIST})
target_link_libraries (Example10 ${EXTRA_LIBS})
add_executable (Example11 ${EXAMPLE11_LIST})
target_link_libraries (Example11 ${EXTRA_LIBS})
add_executable (Example12 ${EXAMPLE12_LIST})
target_link_libraries (Example12 ${EXTRA_LIBS})
add_executable (Example13 ${EXAMPLE13_LIST})
target_link_libraries (Example13 ${EXTRA_LIBS})
add_executable (Example14 ${EXAMPLE14_LIST})
target_link_libraries (Example14 ${EXTRA_LIBS})
add_executable (Example15 ${EXAMPLE15_LIST})
target_link_libraries (Example15 ${EXTRA_LIBS})
add_executable (Example16 ${EXAMPLE16_LIST})
target_link_libraries (Example16 ${EXTRA_LIBS})
add_executable (Example17 ${EXAMPLE17_LIST})
target_link_libraries (Example17 ${EXTRA_LIBS})
add_executable (Example18 ${EXAMPLE18_LIST})
target_link_libraries (Example18 ${EXTRA_LIBS})
add_executable (Example19 ${EXAMPLE19_LIST})
target_link_libraries (Example19 ${EXTRA_LIBS})
