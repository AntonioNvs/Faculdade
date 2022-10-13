#ifndef FOGAO_HPP
#define FOGAO_HPP

#include <iostream>

class Fogao {
    private:
        int numero_de_queimadores;
        int capacidade_forno;

    public:
        Fogao(int queimadores, int capacidade);

        // Retorna o número de queimadores
        int queimadores();

        // Retorna a capacidade do forno
        int capacidade();

};

#endif