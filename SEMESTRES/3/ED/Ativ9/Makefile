#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-06-12 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/avl.o

CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/main

all: run
run: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

$(OBJ)/avl.o: $(HDRS) $(SRC)/avl.c
	$(CC) $(CFLAGS) -o $(OBJ)/avl.o $(SRC)/avl.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out
