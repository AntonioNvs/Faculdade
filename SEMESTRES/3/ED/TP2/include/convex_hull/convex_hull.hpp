/*
    Trabalho Prático - Estrutura de Dados - UFMG, convex_hull.hpp
    Propósito: Definir estruturas gerais da classe ConvexHullAlgorithms;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef CONVEX_HULL
#define CONVEX_HULL

#include <iostream>

#include "animation.hpp"
#include "adt/vector.hpp"
#include "set_of_points.hpp"
#include "linear_equation.hpp"
#include "order_algorithms.hpp"

/*
    @brief Calcula a distância entre dois pontos
    @param Primeiro ponto
    @param Segundo ponto
    @return Distância entre os pontos
*/
int distance(Point p1, Point p2);

/*
    @brief Calcula a orientação entre três pontos
    @param Primeiro ponto
    @param Segundo ponto
    @param Terceiro ponto
    @return Orientação entre os pontos
*/
int orientation(Point p, Point q, Point r);

/*
    @brief Calcula o ângulo polar entre dois pontos
    @param Primeiro ponto
    @param Segundo ponto
    @return Ângulo polar entre os pontos
*/
double polarAngle(const Point& p1, const Point& p2);


/*
    Classe na qual irá armazenar os algoritmos de cálculo da envoltória convexa
*/
class ConvexHullAlgorithms {
    public:
        /*
            @brief Construtor da classe ConvexHullAlgorithms
            @param Referência para a classe Animation
        */
        ConvexHullAlgorithms(Animation &animation);
        ~ConvexHullAlgorithms();

        /*
            @brief Executa o algoritmo de cálculo da envoltória convexa
            @param Conjunto de pontos
            @param Número de pontos
            @param Algoritmo a ser executado, sendo "graham" ou "jarvis"
            @param Método de ordenação a ser utilizado pelo Graham, sendo "linear", "merge" e "insertion"
            @param Flag para animação
            @return Conjunto de pontos da envoltória convexa
        */
        Vector<Point> execute(Point* points, int n_points, std::string algorithm, std::string method_sort, bool animate = false);

        /*
            @brief Executa o algoritmo de cálculo da envoltória convexa de Graham
            @param Conjunto de pontos
            @param Número de pontos
            @param Método de ordenação a ser utilizado pelo Graham, sendo "linear", "merge" e "insertion"
            @param Flag para animação
            @return Conjunto de pontos da envoltória convexa
        */
        Vector<Point> graham(Point* points, int n_points, std::string method_sort, bool animate);

        /*
            @brief Executa o algoritmo de cálculo da envoltória convexa de Jarvis
            @param Conjunto de pontos
            @param Número de pontos
            @param Método de ordenação a ser utilizado pelo Graham, sendo "linear", "merge" e "insertion"
            @param Flag para animação
            @return Conjunto de pontos da envoltória convexa
        */
        Vector<Point> jarvis(Point* points, int n_points, std::string method_sort, bool animate);
    private:
        Animation animation;
};

#endif