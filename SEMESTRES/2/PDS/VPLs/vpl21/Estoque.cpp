#include <string>
#include <iostream>
#include <vector>

#include "Estoque.hpp"

using namespace std;

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(armazem_.find(mercadoria) != armazem_.end())
    armazem_[mercadoria] += qtd;
  else
    armazem_.insert({mercadoria, qtd});
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(armazem_.find(mercadoria) != armazem_.end()) {
    unsigned int total = get_qtd(mercadoria);
    if(total < qtd)
      cout << mercadoria << " insuficiente" << endl;
    else
      armazem_[mercadoria] -= qtd;
  } else
    cout << mercadoria << " inexistente" << endl;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  auto it = armazem_.find(mercadoria);
  if(it != armazem_.end())
    return it->second;
  return 0;
}

void Estoque::imprime_estoque() const {
  // TODO
  for(auto it = armazem_.begin(); it != armazem_.end(); it++)
    cout << it->first << ", " << it->second << endl;
}

vector<string> Estoque::nome_das_mercadorias() const {
  vector<string> names;
  for(auto it = armazem_.begin(); it != armazem_.end(); it++)
    names.push_back(it->first);
  return names;
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  vector<string> names = rhs.nome_das_mercadorias();
  for(string name : names)
    add_mercadoria(name, rhs.get_qtd(name));

  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  vector<string> names = rhs.nome_das_mercadorias();
  for(string name : names)
    sub_mercadoria(name, rhs.get_qtd(name));
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  vector<string> namesL = lhs.nome_das_mercadorias();
  vector<string> namesR = rhs.nome_das_mercadorias();

  for(string nameL : namesL) {
    bool find_name = false;
    for(string nameR : namesR)
      if(nameL == nameR) {
        find_name = true;
        break;
      }
    if(!find_name) return false;
    if(lhs.get_qtd(nameL) >= rhs.get_qtd(nameL)) return false;
  }

  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  vector<string> namesL = lhs.nome_das_mercadorias();
  vector<string> namesR = rhs.nome_das_mercadorias();

  if(namesL.size() < namesR.size()) return false;

  for(string nameR : namesR) {
    bool find_name = false;
    for(string nameL : namesL)
      if(nameL == nameR) {
        find_name = true;
        break;
      }
    if(!find_name) return false;
    if(lhs.get_qtd(nameR) <= rhs.get_qtd(nameR)) return false;
  }

  return true;
}