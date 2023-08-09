#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-04-18 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/expression.o $(OBJ)/infixa.o $(OBJ)/posfixa.o $(OBJ)/main.o
HDRS = $(INC)/queue.hpp $(INC)/stack.hpp $(INC)/operation.hpp $(INC)/expression.hpp $(INC)/posfixa.hpp $(INC)/infixa.hpp
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/main.exe

all: run
run: $(EXE)
	$(EXE) 

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/expression.o: $(HDRS) $(SRC)/expression.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/expression.o $(SRC)/expression.cpp

$(OBJ)/infixa.o: $(HDRS) $(SRC)/infixa.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/infixa.o $(SRC)/infixa.cpp
	
$(OBJ)/posfixa.o: $(HDRS) $(SRC)/posfixa.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/posfixa.o $(SRC)/posfixa.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
