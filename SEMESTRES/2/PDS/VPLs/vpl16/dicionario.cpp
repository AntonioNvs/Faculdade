#include "dicionario.h"

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

Dicionario::Dicionario() {}

Dicionario::~Dicionario() {
  elementos_.clear();
}

int Dicionario::tamanho() {
  return elementos_.size();
}

bool Dicionario::pertence(string chave) {
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    if(it->chave == chave)
      return true;
  return false;
}

string Dicionario::menor() {
  vector<string> keys;

  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    keys.push_back(it->chave);
  
  sort(keys.begin(), keys.end());

  return keys[0];
}

string Dicionario::valor(string chave) {
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    if(it->chave == chave)
      return it->valor;
}

void Dicionario::Inserir(string chave, string valor) {
  elementos_.push_back({chave, valor});
}

void Dicionario::Remover(string chave) {
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    if(it->chave == chave) {
      elementos_.erase(it);
      break;
    }
}

void Dicionario::Alterar(string chave, string valor) {
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    if(it->chave == chave) {
      it->valor = valor;
      break;
    }
}

