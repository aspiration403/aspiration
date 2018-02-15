########################################################################################
#			MAKEFILE FOR CLIENT SERVER COMMUNICATION			##
########################################################################################

CC = gcc
LIBFLAG = `pkg-config --cflags --libs glib-2.0`
CFLAGS = -c -g -Wall
OFLAGS = -o
SRC = ../src/
OBJ = ../obj/
BIN = ../bin/
HEADER = ../include/
INCLUDE = -I../include/

ALL:server	client
server:	$(OBJ)server.o	$(OBJ)server_helper.o	
	$(CC) $(LIBFLAG) $(OFLAGS) server	$(OBJ)server.o	$(OBJ)server_helper.o
	mv	server	$(BIN)

$(OBJ)server.o:	$(SRC)server.c	$(HEADER)server.h	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)server.c	$(INCLUDE)
	mv	server.o	$(OBJ)

$(OBJ)server_helper.o:	$(SRC)server_helper.c	$(HEADER)server.h	$(HEADER)header.h
	$(CC) $(LIBFLAG) $(CFLAGS)	$(SRC)server_helper.c	$(INCLUDE)
	mv	server_helper.o	$(OBJ)
	
client:	$(OBJ)client.o	$(OBJ)client_helper.o
	$(CC) $(OFLAGS) client	$(OBJ)client.o	$(OBJ)client_helper.o
	mv	client	$(BIN)

$(OBJ)client.o:	$(SRC)client.c	$(HEADER)client.h	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)client.c	$(INCLUDE)
	mv	client.o	$(OBJ)

$(OBJ)client_helper.o:	$(SRC)client_helper.c	$(HEADER)client.h	$(HEADER)header.h
	$(CC) $(CFLAGS)	$(SRC)client_helper.c	$(INCLUDE)
	mv	client_helper.o	$(OBJ)
clean:	
	rm	$(OBJ)*.o
	rm	$(BIN)server
	rm	$(BIN)client
	rm	$(BIN)core*



