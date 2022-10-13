#include "fila.h"
#include <iostream>

using namespace std;

Fila::Fila() {
  primeiro_ = NULL;
  ultimo_ = NULL;
}

Fila::~Fila() {
  // FUCK YOU MONITOR
}

string Fila::primeiro() {
  return primeiro_->chave;
}

string Fila::ultimo() {
  return ultimo_->chave;
}

bool Fila::vazia() {
  return (primeiro_ == nullptr);
}

void Fila::Inserir(string name) {
  if(primeiro_ == nullptr) {
    this->primeiro_ = new No();
    this->primeiro_->chave = name;
    this->primeiro_->proximo = nullptr;
    this->ultimo_ = primeiro_;
  } else {
    No* el = primeiro_;
    while(el->proximo != nullptr)
      el = el->proximo;

    el->proximo = new No();
    el->proximo->chave = name;
    el->proximo->proximo = nullptr;
    this->ultimo_ = el->proximo;
  }
}

void Fila::Remover() {
  if(primeiro_->proximo == nullptr) {
    this->primeiro_ = nullptr;
  }
  else {
    No* l = primeiro_->proximo;
    this->primeiro_ = l;
  }
}

int Fila::tamanho() {
  int s = 0;
  
  No* el = primeiro_;

  while(el != NULL) {
    s++;
    el = el->proximo;
  }

  return s;
}