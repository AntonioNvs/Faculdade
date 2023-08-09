#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa operation
# Autor		: Antônio Neves. (antonioneto@dcc.ufmg.br)
# Histórico	: 2023-05-16 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/handle_test.o $(OBJ)/control_time.o $(OBJ)/order_algorithms.o
HDRS = $(INC)/handle_test.hpp $(INC)/control_time.hpp $(INC)/order_algorithms.hpp
CFLAGS = -Wall -c -I $(INC)

EXE = $(BIN)/main

all: run
run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/control_time.o: $(HDRS) $(SRC)/control_time.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/control_time.o $(SRC)/control_time.cpp

$(OBJ)/order_algorithms.o: $(HDRS) $(SRC)/order_algorithms.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/order_algorithms.o $(SRC)/order_algorithms.cpp

$(OBJ)/handle_test.o: $(HDRS) $(SRC)/handle_test.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/handle_test.o $(SRC)/handle_test.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
