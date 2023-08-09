/*
    Trabalho Prático - Estrutura de Dados - UFMG, infixa.hpp
    Propósito: Definir estruturas gerais da classe Infixa;

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#ifndef INFIXA
#define INFIXA

#include <iostream>
#include "operation.hpp"
#include "expression.hpp"

class Infixa : public Expression {
    public:
        Infixa();
        ~Infixa();
        
        /*
            @brief Função que criará a árvore a partir da expressão
            @param exp expressão na qual será a base da construção da árvore
        */
        virtual void build(std::string exp);
        
        /*
            @brief Recursão que constrói a árvore a partir de expressões por parênteses
            @param parts Responsável por entregar uma lista com cada parte da expressão
            @param level Nível atual em que a expressão está
            @param init_idx Início do index de análise
            @param last_idx Index final de análise
            @param size Tamanho da lista de string parts
        */
        NodeOperation* recursion(std::string parts[], int level, int init_idx, int last_idx, int size);

    friend class Expression;
};

#endif