#include "vetor.h"

#include <iostream>

using namespace std;

Vetor::Vetor(int init, int end) {
  if(init > end) {
    throw IntervaloVazio{init, end};
  };

  inicio_ = init;
  fim_ = end;
  elementos_ = new string[end-init+1];
}

Vetor::~Vetor() {
  delete[] elementos_;
}

void Vetor::atribuir(int i, string value) {
  if(i < inicio_ || i > fim_) {
    throw IndiceInvalido{inicio_, fim_, i};
  }
  int idx = i - inicio_;
  elementos_[idx] = value;
}

string Vetor::valor(int i) const {
  if(i < inicio_ || i > fim_) {
    throw IndiceInvalido{inicio_, fim_, i};
  }

  if(elementos_[i-inicio_] == "") {
    throw IndiceNaoInicializado{i};
  };

  return elementos_[i-inicio_];
}