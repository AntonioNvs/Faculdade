#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-07-04 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/huffman.o $(OBJ)/control_time.o
HDRS = $(INC)/priority_queue.hpp $(INC)/map.hpp $(INC)/huffman.hpp $(INC)/vector.hpp
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/main

all: $(EXE)

c: $(EXE)
	$(EXE) -c input.txt output.bin
d: $(EXE)
	$(EXE) -d output.bin output.txt

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/huffman.o: $(HDRS) $(SRC)/huffman.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/huffman.o $(SRC)/huffman.cpp

$(OBJ)/control_time.o: $(HDRS) $(SRC)/control_time.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/control_time.o $(SRC)/control_time.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
