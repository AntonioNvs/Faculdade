#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-03-28 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
ENT = $(SRC)/entities
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/circular_queue.o $(OBJ)/main.o
HDRS = $(INC)/circular_queue.h 
CFLAGS = -Wall -c -pg -ftest-coverage -I $(INC)

EXE = $(BIN)/main

all: run
run: $(EXE)
	$(EXE) 

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/circular_queue.o: $(HDRS) $(SRC)/circular_queue.c
	$(CC) $(CFLAGS) -o $(OBJ)/circular_queue.o $(SRC)/circular_queue.c
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
