/*
    Trabalho Prático - Estrutura de Dados - UFMG, exceptions.hpp
    Propósito: Definir estruturas gerais de exceções utilizadas no sistema;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

// Struct que representa uma exceção quando não houve pontos suficientes na entrada
struct NotEnoughEntryPoints {
    const char * what () const throw () {
        return "Os pontos de entrada não são suficientes para a quantidade de vértices do fecho convexo.";
    }
};

// Struct que representa uma exceção quando depois da execução do algoritmo de cálculo da envoltória convexa, não houve pontos suficientes na saída
struct ColiniearPoints {
    const char * what () const throw () {
        return "Os pontos de entrada são colineares.";
    }
};

#endif