#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-06-18 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/arvexp.o

CFLAGS = -lm

EXE = $(BIN)/main

all: run
run: $(EXE)

$(EXE):
	$(CC) -Dm=2 -DCARGA=100 -o $(EXE) $(SRC)/arvexp.c $(CFLAGS)

clean:
	rm -f $(EXE) $(OBJS) gmon.out
