
# makefile for cmake

cmake_minimum_required (VERSION 2.8)
project (server)

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
    ./content
    ./includes
    ./handler
    ./handler/task
)

# source code list
SET (SRC_LIST
    ./main.cpp
    ./Config.cpp
    ./SendTask.cpp
    ./database.cpp
    ./Evloop.cpp
    ./Sock.c
    ./Single.cpp
    ./ThreadPool.cpp
    ./RecvTask.cpp 
    ./handler/HandleCartoon.cpp
    ./handler/HandleExercise.cpp
    ./handler/HandleClassRoom.cpp
    ./handler/HandleSprite.cpp
    ./handler/HandleBuildHouse.cpp
    ./handler/HandlePuzzle.cpp
    ./handler/HandleMessage.cpp
    ./handler/HandleRainbowValley.cpp
    ./handler/task/BHSyncTask.cpp
    ./ProcessManager.cpp
    ./content/course.cpp
    ./content/courseitem.cpp
    ./content/teacher.cpp
    ./content/room.cpp
    ./content/grade.cpp
    ./content/game.cpp
    ./content/student.cpp
    ./content/roommanager.cpp
    ./content/LoginCheck.cpp
    ./content/makehouse.cpp
    ./content/puzzle.cpp
    ./content/DataTool.cpp
)

# libraries for linker
SET (EXTRA_LIBS 
    -lpthread -lrt -lev -lglog -lmysqlcppconn -llua5.2
)

# how to compiling programs
add_executable (server ${SRC_LIST})
target_link_libraries (server ${EXTRA_LIBS})
