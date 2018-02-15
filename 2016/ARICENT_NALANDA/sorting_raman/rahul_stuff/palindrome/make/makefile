CC = gcc 
CFLAGS = -c -g -Wall
OFLAGS = -o
OUTPUT = ../bin/
SRC = ../src/
OBJ = ../obj/
HEADER = ../include/
VFLAGS = --tool=memcheck

$(BIN)final: $(OBJ)main.o $(OBJ)functions.o
	$(CC) $(OFLAGS) final $(OBJ)main.o $(OBJ)functions.o
	mv final $(OUTPUT)

$(OBJ)main.o:$(SRC)main.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADER) $(SRC)main.c
	mv main.o $(OBJ)

$(OBJ)functions.o:$(SRC)functions.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADER) $(SRC)functions.c
	mv functions.o $(OBJ)

VALGRIND:
	G_SLICE=always-malloc GC_USAGE=gc-friendly valgrind $(VFLAGS) $(OUTPUT)./final $(BIN)input_file $(BIN)output_file

Exe:
	$(OUTPUT)./final $(BIN)input_file $(BIN)output_file

clean:
	rm $(OBJ)*.o
	rm $(OUTPUT)final
