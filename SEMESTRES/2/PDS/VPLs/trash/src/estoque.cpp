#ifndef ESTOQUE_CPP
#define ESTOQUE_CPP

#include "fogao.hpp"
#include "geladeira.hpp"
#include "estoque.hpp"

using namespace std;

Estoque::Estoque(){};

void Estoque::armazena_geladeira(int capacidade, int portas) {
  geladeiras.push_back(Geladeira(capacidade, portas));
}

void Estoque::vende_geladeira(int capacidade, int portas) {
  for(int i = 0; i < quantidade_geladeiras(); i++)
    if(geladeiras[i].capacidade() == capacidade && geladeiras[i].portas() == portas) {
      geladeiras.erase(geladeiras.begin() + i);
      break;
    }
}

void Estoque::armazena_fogao(int queimadores, int capacidade) {
  fogoes.push_back(Fogao(queimadores, capacidade));
}

void Estoque::vende_fogao(int queimadores, int capacidade) {
  for(int i = 0; i < quantidade_fogoes(); i++)
    if(fogoes[i].capacidade() == capacidade && fogoes[i].queimadores() == queimadores) {
      fogoes.erase(fogoes.begin() + i);
      break;
    }
}

void Estoque::exibe_geladeiras() {
  for(auto &geladeira : geladeiras) {
    cout << "G " << geladeira.capacidade() << " ";
    cout << geladeira.portas() << endl;
  }
}

void Estoque::exibe_fogoes() {
  for(auto &fogao : fogoes) {
    cout << "F " << fogao.queimadores() << " ";
    cout << fogao.capacidade() << endl;
  }
}

int Estoque::quantidade_geladeiras() {
  return geladeiras.size();
}

int Estoque::quantidade_fogoes() {
  return fogoes.size();
}

#endif
