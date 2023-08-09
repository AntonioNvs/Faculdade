#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-06-25 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/main.o $(OBJ)/Relacao.o $(OBJ)/ConjuntoDisjunto.o
HDRS = $(INC)/Relacao.hpp $(INC)/ConjuntoDisjunto.hpp
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/main

all: run
run: $(EXE)
	$(EXE)
	gnuplot plot.plt

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) -lgraph -lglut -lGL

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Relacao.o: $(HDRS) $(SRC)/Relacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Relacao.o $(SRC)/Relacao.cpp

$(OBJ)/ConjuntoDisjunto.o: $(HDRS) $(SRC)/ConjuntoDisjunto.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ConjuntoDisjunto.o $(SRC)/ConjuntoDisjunto.cpp

clean:
	rm -f $(EXE) $(OBJS) data.dat grafico.pdf
	
