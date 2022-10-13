#include "racional.h"

#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

int mdc(int a, int b){
  while(b != 0){
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void Racional::Normalizar() {
    int m1 = abs(mdc(numerador_, denominador_));
    int m2 = abs(mdc(denominador_, numerador_));
    int m;

    if(m1 > m2)
      m = m1;
    else
      m = m2;

    numerador_ /= m;
    denominador_ /= m;
}

Racional::Racional() {
    numerador_ = 0; 
    denominador_ = 1;
}

Racional::Racional(int n)  {
    numerador_ = n;
    denominador_ = 1;
}

Racional::Racional(int n, int d) {
    numerador_ = n;
    denominador_ = d;
    Normalizar();
}

int Racional::numerador() const {
    return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  return Racional(-1 * numerador_, denominador_);
}

Racional Racional::somar(Racional k) const {
    Racional x((k.numerador() * denominador_ + k.denominador()*numerador_), k.denominador() *denominador_);
    x.Normalizar();
    return x;
}

Racional Racional::subtrair(Racional k) const {
    Racional x((k.denominador()*numerador_ - k.numerador() * denominador_), k.denominador() *denominador_);
    x.Normalizar();
    return x;
}

Racional Racional::multiplicar(Racional k) const {
    Racional x(numerador_ * k.numerador(), denominador_*k.denominador());
    x.Normalizar();
    return x;
}

Racional Racional::dividir(Racional k) const {
    Racional x(numerador_ * k.denominador(), denominador_*k.numerador());
    x.Normalizar();
    return x;
}