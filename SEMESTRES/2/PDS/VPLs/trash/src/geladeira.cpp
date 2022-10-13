#ifndef GELADEIRA_CPP
#define GELADEIRA_CPP

#include "geladeira.hpp"

Geladeira::Geladeira(int capacidade, int portas) {
  capacidade_em_litros = capacidade;
  numero_de_portas = portas;
}

int Geladeira::capacidade() {
  return capacidade_em_litros;
}

int Geladeira::portas() {
  return numero_de_portas;
}

#endif
