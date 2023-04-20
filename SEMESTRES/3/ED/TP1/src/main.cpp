#include <iostream>
#include <fstream>
#include <string>

#include "expression.hpp"
#include "posfixa.hpp"
#include "infixa.hpp"

using namespace std;

int main() {
    ifstream file; file.open("input.txt");

    Expression exp;

    string expression;
    while(getline(file, expression)) {
        expression = exp.replace_commons_to_dots(expression);     
        
        if(exp.validate(expression))
            cout << "EXPRESSAO OK: " << expression << endl;
        else
            cout << "ERRO: " << expression << " NAO VALIDA" << endl;
        
        Infixa infixa = Infixa();
        infixa.build(expression);
    }

    return 0;
}