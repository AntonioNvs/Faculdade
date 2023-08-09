/*
    Trabalho Prático - Estrutura de Dados - UFMG, linear_equation.cpp
    Propósito: Definir as funcionalidades da classe LinearEquation;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include "set_of_points.hpp"
#include "linear_equation.hpp"

#include <iostream>

LinearEquation::LinearEquation(float alpha, float beta, bool is_vertical = false) {
    this->alpha = alpha;
    this->beta = beta;
    this->is_vertical = is_vertical;
}

std::string LinearEquation::print_equation() {
    if(this->is_vertical) {
        return "x = " + std::to_string(this->beta);
    }
    return std::to_string(this->alpha) + "x + " + std::to_string(this->beta) + " = y";
}

LinearEquation LinearEquation::create_equation(Point p1, Point p2) {
    // Caso a reta seja vertical, não é possível calcular alpha e beta, então é necessário tratar esse caso
    if(p2.x - p1.x == 0) {
        return LinearEquation(0, p1.y, true);
    }

    // Calcular alpha e beta da reta
    float alpha = (float)(p2.y - p1.y)/(float)(p2.x - p1.x);
    float beta = p1.y - alpha*p1.x;

    return LinearEquation(alpha, beta);
}