#include "infixa.hpp"
#include "expression.hpp"
#include "queue.hpp"

#include <string>
#include <sstream>

using namespace std;

Infixa::Infixa() {};

void Infixa::build(string exp) {
    int size = 0;

    // Conseguindo o número de operações que existem na string
    {
        string op;
        stringstream ss(exp);
        while(ss >> op) size++;
    }

    bool visited[size];
    for(int i = 0; i < size; i++) visited[i] = false;

    Queue<char> operations = Queue<char>();
    Queue<double> numbers = Queue<double>();
    
    while(operations.get_size() + numbers.get_size() < size) {
        int index = 0;
        stringstream ss(exp);
        string op;
        bool add_next = false;
        double previous;

        while(ss >> op) {
            if(op == "x" || op == "/") {
                if(!visited[index-1]) {
                    numbers.insert(atof(op.c_str()));
                    visited[index] = true;
                }
                operations.insert(op[0]);
                add_next = true;
            }

            if(add_next && !visited[index]) {
                visited[index] = true;
                numbers.insert(previous);
                add_next = false;
            }

            if(is_digit(op)) previous = atof(op.c_str());

            index++;
        }
    }
};