/*
    Trabalho Prático - Estrutura de Dados - UFMG, linear_equation.hpp
    Propósito: Definir estruturas gerais da classe LinearEquation;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef LINEAR_EQUATION_H
#define LINEAR_EQUATION_H

#include <iostream>
#include "set_of_points.hpp"

/*
    Classe que representa uma equação linear
*/
class LinearEquation {
    public:
        LinearEquation() {}
        
        /*
            @brief Construtor da classe LinearEquation
            @param Coeficiente angular
            @param Coeficiente linear
            @param Flag que indica se a equação é vertical
        */
        LinearEquation(float alpha, float beta, bool is_vertical);

        /*
            @brief Constroi uma string que representa a equação linear
            @return String que representa a equação linear
        */
        std::string print_equation();

        /*
            @brief Constroi uma equação linear a partir de dois ponto
            @param Primeiro ponto
            @param Segundo ponto
            @return Equação linear
        */
        static LinearEquation create_equation(Point p1, Point p2);
    private:
        float alpha;
        float beta;
        bool is_vertical;
};

#endif