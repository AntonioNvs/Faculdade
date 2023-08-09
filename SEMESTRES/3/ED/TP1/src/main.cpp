/*
    Trabalho Prático - Estrutura de Dados - UFMG, main.cpp
    Propósito: Arquivo que junta todas as implementações e manipula as
    classes de acordo com a entrada;

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <cmath>

#include "expression.hpp"
#include "posfixa.hpp"
#include "infixa.hpp"

using namespace std;

int main() {
    ifstream file; file.open("input.txt");

    string operation, line;
    Expression expression;
    Infixa infixa; 
    Posfixa posfixa;

    cout << std::fixed << setprecision(7);
    
    while(getline(file, line)) {
        stringstream ss(line);
        
        ss >> operation;
        if(operation == "LER") {
            infixa = Infixa();
            posfixa = Posfixa();
            
            string type, part, exp;
            ss >> type;
            while(ss >> part) exp += part + ' ';
            
            expression.set_expression(exp);
            expression.replace_commons_to_dots(exp);     

            if(expression.validate(expression.get_expression())) {
                try {
                    if(expression.identify_type_of_expression() == 'p' && type == "POSFIXA") {
                        posfixa.build(expression.get_expression());
                    }
                    else if(expression.identify_type_of_expression() == 'i' && type == "INFIXA") {
                        infixa.build(expression.get_expression());
                    }
                    else
                        throw NotFormattedTree("");

                    cout << "EXPRESSAO OK: " << expression.get_expression() << endl;
                } catch(NotFormattedTree e) {
                    cout << "ERRO: " << expression.get_expression() << " NAO VALIDA" << endl;
                    expression.set_valid(false);
                }
            }
            else
                cout << "ERRO: " << expression.get_expression() << " NAO VALIDA" << endl;
        }
        if(operation == "POSFIXA") {
            if(!expression.is_valid())
                cout << "ERRO: " << expression.get_expression() << "NAO EXISTE" << endl;
            else {
                cout << "POSFIXA: ";
                try {
                    infixa.post_order();
                } catch(NotFormattedTree e) {
                    posfixa.post_order();
                }
                cout << endl;
            }
        }

        if(operation == "INFIXA") {
            if(!expression.is_valid())
                cout << "ERRO: " << expression.get_expression() << "NAO EXISTE" << endl;
            else {
                cout << "INFIXA: ";
                try {
                    posfixa.in_order();
                } catch(NotFormattedTree e) {
                    infixa.in_order();
                }
                cout << endl;
            }
        }

        if(operation == "RESOLVE") {
            if(!expression.is_valid())
                cout << "ERRO: " << expression.get_expression() << "NAO EXISTE" << endl;
            else {
                try {
                    if(expression.identify_type_of_expression() == 'p')
                        cout << "VAL: " << posfixa.solve() << endl;
                    else
                        cout << "VAL: " << infixa.solve() << endl;
                } catch (DivisionByZero e) {
                    cout << "ERRO DIVISÃO POR ZERO" << endl;
                }
            }
        }
    }

    return 0;
}