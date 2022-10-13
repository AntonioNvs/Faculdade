#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include<iostream>
#include "Funcionario.hpp"

using namespace std;

class Professor : public Funcionario {
    friend ostream &operator<<( ostream &, const Professor &);
public:
    Professor(string = "", double = 0.0, string = "", int = 0);
    void setArea(string);
    string getArea() const;
protected:
    string area;
};

#endif
