######################################################################33
#		MAKEFILE FOR READER WRITER				#
########################################################################

CC=gcc
CFLAGS=-g -c -Wall
OFLAGS=-o
SRC=../src/
OBJ=../obj/
BIN=../bin/
HEADER=../include/
INCLUDE=-I../include/

$(BIN)Result:$(OBJ)main.o	$(OBJ)reader_writer.o
	$(CC) $(OFLAGS) Result	$(OBJ)main.o	$(OBJ)reader_writer.o	-lpthread
	mv	Result	$(BIN)

$(OBJ)main.o:$(SRC)main.c	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)main.c	$(INCLUDE)
	mv	main.o	$(OBJ)


$(OBJ)reader_writer.o:$(SRC)reader_writer.c	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)reader_writer.c	$(INCLUDE)
	mv	reader_writer.o	$(OBJ)
run:$(BIN)Result
	$(BIN)Result
	
clean:
	rm $(OBJ)*.o
	rm $(BIN)*



