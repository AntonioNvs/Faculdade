SRC = ./src
BUILD = ./build
INCLUDE = ./include

all:
	g++ -c ${SRC}/entidades/Funcionario.cpp -I ${INCLUDE} -o ${BUILD}/Funcionario.o
	g++ -c ${SRC}/entidades/Pessoa.cpp -I ${INCLUDE} -o ${BUILD}/Pessoa.o
	g++ -c ${SRC}/entidades/Professor.cpp -I ${INCLUDE} -o ${BUILD}/Professor.o
	g++ -c ${SRC}/main.cpp -I ${INCLUDE} -o ${BUILD}/main.o
	
	g++ -o ./vpl_execution ${BUILD}/*.o -I ${INCLUDE}
	