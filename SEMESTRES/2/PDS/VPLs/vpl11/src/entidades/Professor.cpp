#include <iomanip>

#include "Professor.hpp"

using namespace std;

Professor::Professor(string area, double salario, string nome, int idade) : Funcionario(salario, nome, idade) {
    setArea(area);
}

void Professor::setArea(string a) {
    this->area = a;
}

string Professor::getArea() const {
    return this->area;
}


ostream &operator<<(ostream &out, const Professor &p) {
    out << "Funcionario=" << static_cast<Funcionario>(p) << ";Area=" << p.area;
    return out;
}
