#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>
#include "operation.hpp"

class Expression {
    public:
        Expression();
        virtual ~Expression();
        
        bool validate(std::string exp);
        bool is_digit(std::string str);
        std::string replace_commons_to_dots(std::string str);

        virtual void build(std::string exp) { return; };
        virtual float solve() { return 0.0; };
        virtual std::string conversion() { return ""; };
    private:
        Operation* head = nullptr;
};

#endif