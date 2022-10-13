#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    friend ostream &operator<<(ostream &, const Pessoa &);
public:
    Pessoa(string = "", int = 0);
    void setPessoa(string, int);
    string getNome() const { return nome; };
    int getIdade() const { return idade; };
private:
    string nome;
    int idade;
};

#endif
