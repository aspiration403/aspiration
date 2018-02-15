########################################################################################
#			MAKEFILE FOR CLIENT SERVER COMMUNICATION			##
########################################################################################

CC = gcc
LIBFLAG = `pkg-config --cflags --libs glib-2.0`
MYSQL_LIBPATH=-L/usr/lib64/mysql
MYSQL_LIB=-lmysqlclient
MYSQL_HEADER=-I/usr/include/mysql
CFLAGS = -c -g -Wall
OFLAGS = -o
SRC = ../src/
OBJ = ../obj/
BIN = ../bin/
HEADER = ../include/
INCLUDE = -I../include/

ALL:server	client
server:	$(OBJ)server.o	$(OBJ)mysql_function.o		
	$(CC) $(LIBFLAG) $(OFLAGS) server	$(OBJ)server.o 	$(OBJ)mysql_function.o	$(MYSQL_LIBPATH)	$(MYSQL_LIB)
	mv	server	$(BIN)

$(OBJ)server.o:	$(SRC)server.c	$(HEADER)server.h	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)server.c	$(INCLUDE)	$(MYSQL_HEADER)
	mv	server.o	$(OBJ)

$(OBJ)mysql_function.o:	$(SRC)mysql_function.c	$(HEADER)server.h	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)mysql_function.c	$(INCLUDE)	$(MYSQL_HEADER)
	mv	mysql_function.o	$(OBJ)
	
client:	$(OBJ)client.o	
	$(CC) $(OFLAGS) client	$(OBJ)client.o	
	mv	client	$(BIN)

$(OBJ)client.o:	$(SRC)client.c	$(HEADER)client.h	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)client.c	$(INCLUDE)
	mv	client.o	$(OBJ)

clean:	
	rm	$(OBJ)*.o
	rm	$(BIN)server
	rm	$(BIN)client
	rm	$(BIN)core*



