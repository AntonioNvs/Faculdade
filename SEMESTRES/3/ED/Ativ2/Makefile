#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-03-28 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
ENT = $(SRC)/entities
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/factorial.o $(OBJ)/fibonacci.o $(OBJ)/operation.o
HDRS = $(INC)/factorial.hpp $(INC)/fibonacci.hpp $(INC)/operation.hpp 
CFLAGS = -Wall -c -pg -ftest-coverage -I $(INC)

EXE = $(BIN)/main

all: run
run:     	$(EXE)
	$(EXE) fibonacci 5
	gprof $(EXE) gmon.out | more > fibonacci.txt
	$(EXE) factorial 5
	gprof $(EXE) gmon.out | more > factorial.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/factorial.o: $(HDRS) $(ENT)/factorial.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/factorial.o $(ENT)/factorial.cpp

$(OBJ)/fibonacci.o: $(HDRS) $(ENT)/fibonacci.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(ENT)/fibonacci.cpp

$(OBJ)/operation.o: $(HDRS) $(ENT)/operation.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/operation.o $(ENT)/operation.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
