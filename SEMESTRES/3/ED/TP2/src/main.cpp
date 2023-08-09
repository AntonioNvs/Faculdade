/*
    Trabalho Prático - Estrutura de Dados - UFMG, main.cpp
    Propósito: Ser o programa de início de todo o sistema;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include <fstream>
#include <iostream>
#include <getopt.h>

#include "animation.hpp"
#include "handle_test.hpp"
#include "set_of_points.hpp"
#include "order_algorithms.hpp"
#include "convex_hull/graham.hpp"

using namespace std;

void parse_args(int argc, char** argv, bool &animate) {
    int opt;
    while((opt = getopt(argc, argv, "f:a:")) != -1 ) {
        switch(opt) {
            case 'a':
                animate = optarg[0] == 'y';
                break;
            default:
                cout << "Argumento inválido" << endl;
                exit(1);
        }
    }
}

int main(int argc, char** argv) {
    // Lendo o arquivo de entrada
    bool animate = true;
    string input_file = argv[1];
    
    parse_args(argc, argv, animate);

    ifstream infile(input_file);

    // Verificando se o arquivo foi aberto corretamente
    if(!infile.good()) {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
        return 1;
    }

    // Lendo o arquivo de entrada
    SetOfPoints set_points;
    set_points.define_points_by_input_file(infile);
    
    Animation animation;

    animation = Animation(argc, argv);
    HandleTest handle_test = HandleTest(animation);
    handle_test.execute(set_points.get_points(), set_points.get_n_points(), animate);
    animation.destroyWindow();
    
    infile.close();

    return 0;
}