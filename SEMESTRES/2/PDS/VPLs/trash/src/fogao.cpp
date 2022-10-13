#ifndef FOGAO_CPP
#define FOGAO_CPP

#include "fogao.hpp"

Fogao::Fogao(int queimadores, int capacidade) {
  numero_de_queimadores = queimadores;
  capacidade_forno = capacidade;
}

int Fogao::queimadores() {
  return numero_de_queimadores;
}

int Fogao::capacidade() {
  return capacidade_forno;
}

#endif
