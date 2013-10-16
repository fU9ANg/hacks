CPP=ccache g++ 
CC=ccache gcc
CFLAGS=-Wall -O0 -Werror -g
LINKS	= -lpthread -lrt -lev -lglog -lmysqlcppconn -llua5.2 -lgtest

OBJS	= twomapT_unittest.o \
		  PoolT_unittest.o \
		  Buf_unittest.o \
		  libev_unittest.o \
		  database_unittest.o \
		  follow_unitest.o \
          ../ThreadPool.o \
		  ../ProcessManager.o \
		  ../Single.o \
		  ../Sock.o \
		  ../Evloop.o \
		  ../RecvTask.o \
		  ../SendTask.o \
		  ../database.o \
		  ../handler/HandleBuildHouse.o \
		  ../handler/HandleCartoon.o \
		  ../handler/HandleClassRoom.o \
		  ../handler/HandleExercise.o \
		  ../handler/HandleMessage.o \
		  ../handler/HandlePuzzle.o \
		  ../handler/HandleSprite.o \
		  ../content/LoginCheck.o \
		  ../content/class.o \
		  ../content/course.o \
		  ../content/courseitem.o \
		  ../content/grade.o \
		  ../content/room.o \
		  ../content/game.o \
		  ../content/roommanager.o \
		  ../content/student.o \
		  ../content/teacher.o \
		  ../content/makehouse.o \
		  ../content/puzzle.o \
		  ../Config.o \
		  gtest_main.o
#Evloop_unittest.o \

EXE=test.out

VPATH		 = ./../

INC=-I.\
	-I./../ \
	-I./../content \
	-I./../handler \
	-I$(HOME)/Downloads/gtest-1.6.0/include

LIB=-L.\
	-L./../ \
	-L$(HOME)/Downloads/gtest-1.6.0/lib/.libs

all:clean $(EXE)

$(EXE):$(OBJS)
		 $(CPP) $(CFLAGS) $(LIB) $(OBJS) -o $@ $(LINKS)

%.o:%.cc
		 $(CPP) $(CFLAGS) $(INC) -c $< -o $@

%.o:%.cpp
		 $(CPP) $(CFLAGS) $(INC) -c $< -o $@

%.o:%.c
		 $(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJS) 
	rm -rf $(EXE) 
	rm -rf core*
	rm -rf logs
	rm -f .lock
