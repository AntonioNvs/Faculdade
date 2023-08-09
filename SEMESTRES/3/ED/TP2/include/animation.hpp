/*
    Trabalho Prático - Estrutura de Dados - UFMG, animation.hpp
    Propósito: Definir estruturas gerais da classe Animation;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "adt/vector.hpp"
#include "set_of_points.hpp"

// Struct que representa uma Cor no sistema RGB
struct Color {
    float r, g, b;
};

/*
    Responśavel em controlar a animação em tela durante a execução do programa
*/
class Animation {
    public:
        
        Animation() {};
        
        /*
            @brief Construtor da classe Animation, que recebe os argumentos da linha de comando
            @param Número de argumentos
            @param Vetor de argumentos
        */
        Animation(int argc, char **argv);
        
        ~Animation();

        /*
            @brief Mantem a janela em Loop até que uma força externa force a saída
        */
        void setLoop();
        
        /*
            @brief Espera um tempo em milisegundos
            @param Tempo em milisegundos
        */
        void wait(int ms);
        
        /*
            @brief Limpa a tela
        */
        void clearScreen();
        
        /*
            @brief Destroi a janela
        */
        void destroyWindow();

        /*
            @brief Desenha o título da animação
            @param Título a ser desenhado
            @param Se deve ou não atualizar a tela
        */
        void draw_title_screen(std::string title, bool flush = true);

        /*
            @brief Desenha um ponto na tela
            @param Ponto a ser desenhado
            @param Cor do ponto
            @param Tamanho do ponto
            @param Se deve ou não atualizar a tela
        */
        void draw_point(Point p, Color color, float dot_size = 3.0, bool flush = true);
        
        /*
            @brief Desenha uma linha na tela
            @param Primeiro ponto da linha
            @param Segundo ponto da linha
            @param Cor da linha
            @param Largura da linha
            @param Se deve ou não atualizar a tela
        */
        void draw_line(Point p1, Point p2, Color color, double width = 5.0, bool flush = true);
        
        /*
            @brief Desenha um conjunto de pontos na tela
            @param Vetor de pontos
            @param Número de pontos
            @param Cor a ser desenhada dos pontos
            @param Tamanho dos pontos
            @param Delay de desenho entre cada ponto
            @param Se deve ou não atualizar os parâmetros de normalização com base nesse conjunto de pontos
        */
        void draw_points(Point *points, int n, Color color, float dot_size = 3.0, int delay = 1, bool define_params = true);
        
        /*
            @brief Itera sobre um conjunto de pontos e desenha as linhas entre eles
            @param Vetor de pontos
            @param Número de pontos
            @param Vetor de pontos que compõem o envoltório convexo
            @param Método de calculo do envoltório para compor o título
            @param Se deve ou não apagar as linhas desenhadas
        */
        void draw_iteration_lines(Point *points, int n, Vector<Point> &convex_hull, std::string method = "graham", bool delete_lines = true);
    private:
        // Parâmetros de normalização
        double maxX, minX, maxY, minY;
        double midX, midY;
        double K;
};

#endif