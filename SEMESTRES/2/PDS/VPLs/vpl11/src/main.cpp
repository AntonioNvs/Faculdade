#include <iostream>

#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Professor.hpp"

using namespace std;

int main() {
    std::cout << "PDS2 - Makefile" << std::endl;

    Pessoa pessoa("Joao",72);
    cout << "Pessoa: " << pessoa << endl;

    Funcionario funcionario(1000,"Ricardo",72);
    cout << "Funcionario: " << funcionario << endl;

    Professor professor("Computacao",20000,"Leonardo",25);
    cout << "Professor: " << professor << endl;

    return 0;
}
