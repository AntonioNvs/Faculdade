/*
    Trabalho Prático - Estrutura de Dados - UFMG, graham.hpp
    Propósito: Definir estruturas gerais da classe Graham;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef GRAHAM
#define GRAHAM

#include "animation.hpp"
#include "adt/vector.hpp"
#include "set_of_points.hpp"
#include "order_algorithms.hpp"

/*
    @brief Compara utilizando um determinado critério dois pontos
    @param Primeiro ponto
    @param Segundo ponto
    @return Valor de retorno usando o critério
*/
bool compare(Point p1, Point p2);

/*
    Classe de cálculo do envoltório convexo
*/
class Graham {
    public:
        /*
            @brief Construtor da classe Graham
            @param Referência para a classe Animation
        */
        Graham(Animation &animation);
        ~Graham();

        /*
            @brief Troca dois pontos de posição em um vetor
            @param Primeiro ponto
            @param Segundo ponto
        */
        void swap(Point &p1, Point &p2);

        /*
            @brief Retorna o penúltimo ponto da pilha
            @param Vetor de pontos, que se comporta como uma pilha também
            @return Penúltimo ponto da pilha
        */
        Point next_to_top(Vector<Point> &arr);

        /*
            @brief Execução principal do algoritmo
            @param Conjunto de pontos
            @param Número de pontos
            @param Método de ordenação
            @param flag de Animação
            @return Vetor de pontos que compõem o envoltório convexo
        */
        Vector<Point> execute(Point* points, int n_points, std::string method_sort, bool animate);
    private:
        Point p0;
        Animation animation;
        OrderAlgorithms<Point>* order_algorithms;
};

#endif