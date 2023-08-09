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

ADT = $(INC)/adt

OBJS = $(OBJ)/main.o $(OBJ)/set_of_points.o $(OBJ)/linear_equation.o $(OBJ)/convex_hull.o $(OBJ)/jarvis.o $(OBJ)/graham.o $(OBJ)/control_time.o $(OBJ)/handle_test.o  $(OBJ)/animation.o
HDRS = $(INC)/set_of_points.hpp $(INC)/linear_equation.hpp $(INC)/order_algorithms.hpp $(INC)/convex_hull/convex_hull.hpp $(INC)/convex_hull/jarvis.hpp $(INC)/convex_hull/graham.hpp $(ADT)/vector.hpp $(INC)/animation.hpp $(INC)/control_time.hpp $(INC)/handle_test.hpp $(INC)/exceptions.hpp
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/fecho

all: run
run: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) -lgraph -lglut -lGL

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/set_of_points.o: $(HDRS) $(SRC)/set_of_points.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/set_of_points.o $(SRC)/set_of_points.cpp

$(OBJ)/linear_equation.o: $(HDRS) $(SRC)/linear_equation.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/linear_equation.o $(SRC)/linear_equation.cpp

$(OBJ)/convex_hull.o: $(HDRS) $(SRC)/convex_hull/convex_hull.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/convex_hull.o $(SRC)/convex_hull/convex_hull.cpp

$(OBJ)/graham.o: $(HDRS) $(SRC)/convex_hull/graham.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graham.o $(SRC)/convex_hull/graham.cpp

$(OBJ)/jarvis.o: $(HDRS) $(SRC)/convex_hull/jarvis.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/jarvis.o $(SRC)/convex_hull/jarvis.cpp

$(OBJ)/control_time.o: $(HDRS) $(SRC)/control_time.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/control_time.o $(SRC)/control_time.cpp

$(OBJ)/handle_test.o: $(HDRS) $(SRC)/handle_test.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/handle_test.o $(SRC)/handle_test.cpp

$(OBJ)/animation.o: $(HDRS) $(SRC)/animation.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/animation.o $(SRC)/animation.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out output.csv
