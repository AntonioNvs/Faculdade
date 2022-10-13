#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, int idade) {
    setPessoa(nome, idade);
}

void Pessoa::setPessoa(string nome, int idade) {
    this->nome = nome;
    this->idade = idade;
}

ostream &operator<<(ostream &out, const Pessoa &p) {
    out << '[' << p.nome << ',' << p.idade << ']';
    return out;
}
