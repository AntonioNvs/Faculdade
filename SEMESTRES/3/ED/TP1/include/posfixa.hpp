#ifndef POSFIX
#define POSFIX

#include <iostream>
#include "expression.hpp"

class Posfixa : public Expression {
    public:
        Posfixa();
        virtual void build(std::string exp);
        
    friend class Expression;
};

#endif