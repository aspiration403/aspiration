CC = gcc -fprofile-arcs -ftest-coverage
CFLAGS = -c -g -Wall
OFLAGS = -o
OUTPUT = ../bin/
OBJ = ../obj/
SRC = ../src/

$(OUTPUT)final:	$(OBJ)main.o	$(OBJ)sub.o
	$(CC) $(OFLAGS) final $(OBJ)main.o $(OBJ)sub.o
	#mv final $(OUTPUT)

$(OBJ)main.o:	$(SRC)main.c
	$(CC) $(CFLAGS) $(SRC)main.c
	mv main.o $(OBJ)

$(OBJ)sub.o:	$(SRC)sub.c
	$(CC) $(CFLAGS) $(SRC)sub.c
	mv sub.o $(OBJ)
Exe:
	#$(OUTPUT)final
	final
clean:
	rm $(OBJ)*.o
	rm $(OUTPUT)final

GCOV:
	gcov	$(SRC)*.c
	cat	m*.gcov
	read
	cat	s*.gcov	




	
