#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
  if(lista_.empty()) {
    lista_.push_back(p);
    return;
  }
  
  list<Pessoa>::iterator it;
  for(it = lista_.begin(); it != lista_.end(); it++) 
    if(p.prioridade > it->prioridade) {
      lista_.insert(it, p);
      return;
    }

  lista_.push_back(p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string name = lista_.front().nome;
  lista_.pop_front();
  return name;
}

void FilaDePrioridade::Remover(string nome) {
  list<Pessoa>::iterator it;

  for(it = lista_.begin(); it != lista_.end(); it++)
    if(it->nome == nome) {
      lista_.erase(it);
      return;
    }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;

  list<Pessoa>::iterator it;
  for(it = lista_.begin(); it != lista_.end(); it++)
    v.push_back(it->nome);
  return v; 
}