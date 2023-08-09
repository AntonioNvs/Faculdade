#include "stack.hpp"
#include "posfixa.hpp"
#include "operation.hpp"
#include "expression.hpp"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Posfixa::Posfixa() {}

void Posfixa::build(string exp) {
    Stack<NodeOperation *> nodes = Stack<NodeOperation*>();

    string op;
    stringstream ss(exp);

    while(ss >> op) {
        if(op == "*" || op == "+" || op == "-" || op == "/") {
            NodeOperation* r = nodes.top(); nodes.pop();
            NodeOperation* l = nodes.top(); nodes.pop();
            nodes.insert(new NodeOperation(op[0], l, r));
        } else {
            nodes.insert(new NodeOperation(atof(op.c_str())));
        }
    }

    head = nodes.top();
}