/*
    Trabalho Prático - Estrutura de Dados - UFMG, posfixa.cpp
    Propósito: Definir as funcionalidades da classe Posfixa;

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#include "stack.hpp"
#include "posfixa.hpp"
#include "operation.hpp"
#include "expression.hpp"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Posfixa::Posfixa() {}

Posfixa::~Posfixa() {
    exclude_tree(head);
}

void Posfixa::build(string exp) {
    Stack<NodeOperation *> nodes = Stack<NodeOperation*>();

    string op;
    stringstream ss(exp);

    try {
        while(ss >> op) {
            if(op == "*" || op == "+" || op == "-" || op == "/") {
                NodeOperation* r = nodes.top(); nodes.pop();
                NodeOperation* l = nodes.top(); nodes.pop();
                nodes.insert(new NodeOperation(op[0], l, r));
            } else {
                nodes.insert(new NodeOperation(atof(op.c_str())));
            }

        }
    } catch (EmptyStack e) {
        throw NotFormattedTree(e.message);
    }
    head = nodes.top();
}