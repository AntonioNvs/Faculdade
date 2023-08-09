/*
    Trabalho Prático - Estrutura de Dados - UFMG, posfixa.hpp
    Propósito: Definir estruturas gerais da classe Posfixa

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#ifndef POSFIX
#define POSFIX

#include <iostream>
#include "expression.hpp"

class Posfixa : public Expression {
    public:
        Posfixa();
        ~Posfixa();
        
        /*
            Função que criará a árvore a partir da expressão
            @param exp expressão na qual será a base da construção da árvore
        */
        virtual void build(std::string exp);
        
    friend class Expression;
};

#endif