######################## MAKEFILE FOR CLIENT/SERVER ###########################
CC = gcc
CFLAGS = -c -g -Wall 
OFLAGS = -o
HEADER = ./../include/
INCLUDE = -I./../include/
SRC= ./../src/
OBJ = ./../obj/
BIN = ./../bin/

All: server	client
server:	$(OBJ)server.o
				$(CC)	$(OFLAGS) server	$(OBJ)server.o 
				mv	server	$(BIN)

$(OBJ)server.o:	$(SRC)server.c	
			$(CC)	$(CFLAGS)	$(SRC)server.c	$(INCLUDE)
			mv	server.o	$(OBJ)

client:	$(OBJ)client.o
				$(CC)	$(OFLAGS) client	$(OBJ)client.o 
				mv	client 	$(BIN)

$(OBJ)client.o:	$(SRC)client.c
			$(CC)	$(CFLAGS)	$(SRC)client.c	$(INCLUDE)
			mv	client.o	$(OBJ)

clean:
	rm	$(OBJ)*
	rm 	$(BIN)*

run:
	$(BIN)client

gdb:
	gdb $(BIN)client
