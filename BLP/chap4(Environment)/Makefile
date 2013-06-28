#
# Makefile for chap 4 of BLP
#

CC          =    gcc
CFLAGS      =   -Wall -Werror
#CFLAGS      =
DEBUG       =   -g
INCLUDES    =   -I.
LIBRARYS    =   -L.
BIN			=	argopt args ctime environ envtime gmtime hostget limits logmask showenv strftime syslog tmpnam user

all:$(BIN)

argopt:argopt.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
args:args.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
ctime:ctime.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
environ:environ.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
envtime:envtime.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
gmtime:gmtime.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
hostget:hostget.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
limits:limits.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS) -lm
logmask:logmask.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
showenv:showenv.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
strftime:strftime.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
syslog:syslog.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
tmpnam:tmpnam.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)
user:user.o
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ $< $(LIBRARYS)

%.o:%.c
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o *~ $(BIN) file.out
