#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>
#include "operation.hpp"

class Expression {
    public:
        Expression();
        ~Expression();
        
        bool recognition(std::string exp);
        virtual std::string conversion();
        virtual float solve();
    private:
        Operation* head = nullptr;
};

#endif