#ifndef INFIXA
#define INFIXA

#include <iostream>
#include "expression.hpp"

class Infixa : Expression {
    public:
        Infixa();
        virtual void build(std::string exp);
};

#endif