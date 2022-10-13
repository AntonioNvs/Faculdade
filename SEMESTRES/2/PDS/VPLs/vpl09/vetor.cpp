#include "vetor.h"

#include <iostream>

using namespace std;

Vetor::Vetor(int init, int end) {
  inicio_ = init;
  elementos_ = new string[end-init+1];
}

Vetor::~Vetor() {
  delete[] elementos_;
}

void Vetor::atribuir(int i, string value) {
  int idx = i - inicio_;
  elementos_[idx] = value;
}

string Vetor::valor(int i) const {
  return elementos_[i-inicio_];
}