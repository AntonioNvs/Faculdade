#ifndef INFIXA
#define INFIXA

#include <iostream>
#include "operation.hpp"
#include "expression.hpp"

class Infixa : public Expression {
    public:
        Infixa();
        virtual void build(std::string exp);
        
        NodeOperation* recursion(std::string parts[], int level, int init_idx, int last_idx, int size);

    friend class Expression;
};

#endif