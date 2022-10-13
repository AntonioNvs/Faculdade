// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  size = 0;
  degree = 0;
}

Complexo::Complexo(double a, double b) {
  size = sqrt(pow(a, 2) + pow(b, 2));
  degree = atan(b/a);
}

double Complexo::real() {
  return size*cos(degree);
}

double Complexo::imag() {
  return size * sin(degree);
}

bool Complexo::igual(Complexo x) {
  return x.real() == real() && x.imag() == imag();
}

void Complexo::Atribuir(Complexo x) {
  this->size = x.size;
  this->degree = x.degree;
}

double Complexo::modulo() {
  return size;
}

Complexo Complexo::conjugado() {
  return Complexo(real(), -imag());
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.size = -size;
  c.degree = -degree;
  return c;
}

Complexo Complexo::inverso() {
  return Complexo(real() / pow(modulo(), 2), -imag() / pow(modulo(), 2));
}

Complexo Complexo::somar(Complexo y) {
  return Complexo(real() + y.real(), imag() + y.imag());
}

Complexo Complexo::subtrair(Complexo y) {
  return Complexo(real() - y.real(), imag() - y.imag());
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.size = y.size * size;
  p.degree = y.degree + degree;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo p;
  p.size = y.size / size;
  p.degree = y.degree - degree;
  return p;
}
