#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-04-25 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o
# HDRS = $(INC)/queue.hpp $(INC)/stack.hpp $(INC)/operation.hpp $(INC)/expression.hpp $(INC)/posfixa.hpp $(INC)/infixa.hpp
CFLAGS = -Wall -g -c -I $(INC)

EXE = $(BIN)/main

all: run
run: $(EXE)
	$(EXE) -o output.txt -s 10 -n 10

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out
