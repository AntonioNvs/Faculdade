#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>
#include "operation.hpp"

struct NotFormattedTree {
    std::string message;
    NotFormattedTree(std::string msg) : message(msg) {};
};

class Expression {
    public:
        Expression();
        virtual ~Expression();
        
        bool is_digit(std::string str);
        bool validate(std::string exp);
        bool is_valid() { return validated; };

        char identify_type_of_expression();
        
        std::string get_expression() { return sentence; }
        void set_expression(std::string line) { sentence = line; }

        double solve();
        void replace_commons_to_dots(std::string &str);
        
        void post_order();
        void in_order();
        
        virtual void build(std::string exp) { return; };
    protected:
        NodeOperation* head = nullptr;
    private:
        std::string sentence;
        bool validated = false;
};

#endif