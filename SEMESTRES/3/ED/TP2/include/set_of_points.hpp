/*
    Trabalho Prático - Estrutura de Dados - UFMG, set_of_points.hpp
    Propósito: Definir estruturas gerais da classe SetOfPoints;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef GEOMETRY
#define GEOMETRY

#include <fstream>
#include <iostream>

#include "adt/vector.hpp"

// Struct que representa um ponto
struct Point {
    int x;
    int y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

/*
    @brief Calcula informações de mínimo e máximo dos eixos
    @param String que representa se é mínimo ou máximo
    @param String que representa o eixo
    @param Vetor de pontos
    @param Tamanho do vetor de pontos
    @return Ponto que representa a informação determinada
*/
Point getInfo(std::string minMax, std::string axe, Point * points, int size);


class SetOfPoints {
    public:
        SetOfPoints();
        ~SetOfPoints();

        /*
            @brief Define pontos a partir de um arquivo de entrada
            @param Arquivo de entrada
        */
        void define_points_by_input_file(std::ifstream & file);

        /*
            @brief Adquire os pontos salvados na classe
            @return Vetor de pontos
        */
        Point* get_points();

        /*
            @brief Adquire o número de pontos salvos na classe
            @return Número de pontos
        */
        int get_n_points();

        /*
            @brief Printa de forma formatada os pontos salvos na classe
        */
        void print();
        
    private:
        // Vetor de pontos para cache
        Vector<Point> points = Vector<Point>();
};

#endif