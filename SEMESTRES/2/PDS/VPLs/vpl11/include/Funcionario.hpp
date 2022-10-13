#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>

#include "Pessoa.hpp"

using namespace std;

class Funcionario : public Pessoa {
    friend ostream &operator<<( ostream &, const Funcionario & );
public:
    Funcionario(double = 0.0, string = "", int = 0);
    void setSalario(double);
    double getSalario() const;
protected:
    double salario;
};

#endif
