#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "expression.hpp"
#include "posfixa.hpp"
#include "infixa.hpp"

using namespace std;

int main() {
    ifstream file; file.open("input.txt");

    string operation, line, exp;
    Expression expression;
    Infixa infixa = Infixa(); 
    Posfixa posfixa = Posfixa();

    cout << std::fixed << setprecision(10);

    while(getline(file, line)) {
        stringstream ss(line);
        
        ss >> operation;
        if(operation == "LER") {
            string part;
            while(ss >> part) exp += part + ' ';
            
            expression.set_expression(exp);
            expression.replace_commons_to_dots(exp);     

            if(expression.validate(expression.get_expression())) {
                cout << "EXPRESSAO OK: " << expression.get_expression() << endl;
                if(expression.identify_type_of_expression() == 'p')
                    posfixa.build(expression.get_expression());
                else
                    infixa.build(expression.get_expression());
            }
            else
                cout << "ERRO: " << expression.get_expression() << " NAO VALIDA" << endl;
        }
        if(operation == "POSFIXA") {
            if(!expression.is_valid())
                cout << "ERRO: " << expression.get_expression() << "NAO EXISTE" << endl;
            else {
                cout << "POSFIXA: ";
                infixa.post_order();
                cout << endl;
            }
        }

        if(operation == "INFIXA") {
            if(!expression.is_valid())
                cout << "ERRO: " << expression.get_expression() << "NAO EXISTE" << endl;
            else {
                cout << "INFIXA: ";
                posfixa.in_order();
                cout << endl;
            }
        }

        if(operation == "RESOLVE") {
            if(!expression.is_valid())
                cout << "ERRO: " << expression.get_expression() << "NAO EXISTE" << endl;
            else {
                if(expression.identify_type_of_expression() == 'p')
                    cout << "VAL: " << posfixa.solve() << endl;
                else
                    cout << "VAL: " << infixa.solve() << endl;
            }
        }
    }

    return 0;
}