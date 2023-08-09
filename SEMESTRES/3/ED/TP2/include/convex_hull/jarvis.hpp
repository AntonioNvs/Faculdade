/*
    Trabalho Prático - Estrutura de Dados - UFMG, jarvis.hpp
    Propósito: Definir estruturas gerais da classe Jarvis;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef JARVIS
#define JARVIS

#include "animation.hpp"
#include "set_of_points.hpp"
#include "order_algorithms.hpp"

/*
    Classe de cálculo do envoltório convexo
*/
class Jarvis {
    public:
        /*
            @brief Construtor da classe Jarvis
            @param Referência para a classe Animation
        */
        Jarvis(Animation &animation);
        ~Jarvis();

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
        Animation animation;
        OrderAlgorithms<Point>* order_algorithms;
};

#endif