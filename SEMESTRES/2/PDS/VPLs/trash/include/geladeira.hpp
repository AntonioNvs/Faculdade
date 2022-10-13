#ifndef GELADEIRA_HPP
#define GELADEIRA_HPP

#include <iostream>

class Geladeira {
    private:
        int capacidade_em_litros;
        int numero_de_portas;

    public:
        Geladeira(int capacidade, int portas);
        
        // Retorna a capacidade da geladeira
        int capacidade();
        
        // Retorna o número de portas
        int portas();

};

#endif