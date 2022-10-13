CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -Wall -O3 -std=c++11 -I include/

all: main

fogao:
	$(CC) -c $(CFLAGS) $(SRCDIR)/fogao.cpp -o $(BUILDDIR)/fogao.o
geladeira:
	$(CC) -c $(CFLAGS) $(SRCDIR)/geladeira.cpp -o $(BUILDDIR)/geladeira.o
estoque:
	$(CC) -c $(CFLAGS) $(SRCDIR)/estoque.cpp -o $(BUILDDIR)/estoque.o

# Modifique a funcao main
main: fogao geladeira estoque
	$(CC) $(CFLAGS) build/fogao.o build/geladeira.o build/estoque.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
