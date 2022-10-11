SRC = ./src
BUILD = ./build
ENTITIES = ${SRC}/entities
INCLUDE = ./include

all: main.exe

main.exe: ${BUILD}/Person.o ${BUILD}/Product.o ${BUILD}/Hurl.o ${BUILD}/Auction.o ${BUILD}/main.o
	g++ -o ./main ${BUILD}/*.o -I ${INCLUDE}

	
${BUILD}/Person.o:
	g++ -c ${ENTITIES}/Person.cpp -I ${INCLUDE} -o ${BUILD}/Person.o

${BUILD}/Product.o:
	g++ -c ${ENTITIES}/Product.cpp -I ${INCLUDE} -o ${BUILD}/Product.o

${BUILD}/Hurl.o:
	g++ -c ${ENTITIES}/Hurl.cpp -I ${INCLUDE} -o ${BUILD}/Hurl.o

${BUILD}/Auction.o:
	g++ -c ${ENTITIES}/Auction.cpp -I ${INCLUDE} -o ${BUILD}/Auction.o

${BUILD}/main.o:
	g++ -c ${SRC}/main.cpp -I ${INCLUDE} -o ${BUILD}/main.o