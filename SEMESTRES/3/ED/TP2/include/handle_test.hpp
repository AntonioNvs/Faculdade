/*
    Trabalho Prático - Estrutura de Dados - UFMG, handle_test.hpp
    Propósito: Definir estruturas gerais da classe HandleTest.;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef HANDLE_TEST
#define HANDLE_TEST

#include "animation.hpp"
#include "control_time.hpp"
#include "set_of_points.hpp"
#include "convex_hull/convex_hull.hpp"

/*
    Classe na qual irá determinar como será a execução principal dos testes de cálculo do envoltório convexo
*/
class HandleTest {
    public:
        /*
            @brief Construtor da classe HandleTest
            @param Referência para a classe Animation
        */
        HandleTest(Animation &animation);
        ~HandleTest();

        /*
            @brief Executa o conjunto de testes do cálculo da envoltória convexa
            @param Conjunto de pontos
            @param Número de pontos
            @param flag de Animação
        */
        void execute(Point *points, int n_points, bool animate);
    private:
        Animation animation;
        ControlTime *control_time = nullptr;
        ConvexHullAlgorithms *convex_hull = nullptr;
};

#endif