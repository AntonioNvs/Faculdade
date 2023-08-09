#include "infixa.hpp"
#include "expression.hpp"
#include "queue.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Infixa::Infixa() {};

NodeOperation * Infixa::recursion(string parts[], int level, int init_idx, int last_idx, int size) {
    int crr_level = level;

    Queue<OperatorFormat> operations = Queue<OperatorFormat>();
    Queue<NodeFormat> numbers = Queue<NodeFormat>();

    int visited[size];
    for(int i = init_idx; i <= last_idx; i++) {
        visited[i] = crr_level;
        if(parts[i] == "(")
            crr_level++;
        if(parts[i] == ")") {
            crr_level--;
            visited[i] = crr_level;
        }
    }

    int idx_next = -1;
    NodeOperation* previous = nullptr;

    int i = init_idx;
    while(i <= last_idx) {
        if(parts[i] == "*" || parts[i] == "/") {
            if(visited[i-1] != -1) {
                numbers.insert({previous, i});        
                visited[i-1] = -1;
                previous = nullptr;
            }
            operations.insert({ parts[i][0], i});
            idx_next = i;
        }
        else if(idx_next != -1) {
                if(visited[i] != -1) {
                    if(is_digit(parts[i]))
                        numbers.insert({new NodeOperation(atof(parts[i].c_str())), idx_next});
                    else {
                        int end_idx = i+1;
                        while(visited[end_idx] > level) end_idx++;

                        numbers.insert({ recursion(parts, level+1, i+1, end_idx-1, size), idx_next });
                        i = end_idx;
                    }
                    visited[i] = -1;
                }
                idx_next = -1;
            }

        else if(is_digit(parts[i]))
            previous = new NodeOperation(atof(parts[i].c_str()));
        else if(parts[i] == "("){
            int end_idx = i+1;
            while(visited[end_idx] > level) end_idx++;
            
            previous = recursion(parts, level+1, i+1, end_idx-1, size);

            i = end_idx;
        }

        i++;
    }

    idx_next = -1;
    previous = nullptr;
    i = init_idx;

    while(i <= last_idx) {
        if(parts[i] == "+" || parts[i] == "-") {
            if(visited[i-1] != -1) {
                numbers.insert({previous, i});        
                visited[i-1] = -1;
                previous = nullptr;
            }
            operations.insert({ parts[i][0], i});
            idx_next = i;
        }
        else if(idx_next != -1) {
                if(visited[i] != -1) {
                    if(is_digit(parts[i]))
                        numbers.insert({new NodeOperation(atof(parts[i].c_str())), idx_next});
                    else {
                        int end_idx = i+1;
                        while(visited[end_idx] > level) end_idx++;

                        numbers.insert({ recursion(parts, level+1, i+1, end_idx-1, size), idx_next });
                        i = end_idx;
                    }
                    visited[i] = -1;
                }
                idx_next = -1;
            }

        else if(is_digit(parts[i]))
            previous = new NodeOperation(atof(parts[i].c_str()));
        else if(parts[i] == "("){
            int end_idx = i+1;
            while(visited[end_idx] > level) end_idx++;

            previous = recursion(parts, level+1, i+1, end_idx-1, size);

            i = end_idx;
        }

        i++;
    }
    
    if(previous != nullptr && numbers.empty()) numbers.insert({previous, 0});

    Queue<NodeOperation*> nodes = Queue<NodeOperation*>();


    while(!operations.empty() || !numbers.empty()) {
        if(numbers.get_size() == 1 && operations.empty()) {
            return numbers.see_front().value;
        }
        if(numbers.empty() || numbers.see_front().index != operations.see_front().index) {
            NodeOperation* f = nodes.see_front();
            nodes.pop_front();
            nodes.insert(new NodeOperation(operations.see_front().value, f, nodes.see_front()));
            nodes.pop_front(); operations.pop_front();
            

            if(operations.empty()) break;
            else continue;
        }

        NodeFormat fn = numbers.see_front(); numbers.pop_front();
        OperatorFormat op = operations.see_front(); operations.pop_front();

        if(fn.index == op.index && (numbers.empty() || numbers.see_front().index != op.index)) {
            NodeOperation* f = nodes.see_front(); nodes.pop_front();
            NodeOperation* nn = fn.value;
            nodes.insert(new NodeOperation(op.value, f, nn));

        } else if(fn.index == op.index && numbers.see_front().index == op.index) {
            NodeOperation* nf = fn.value;
            NodeOperation* ns = numbers.see_front().value; numbers.pop_front();
            nodes.insert(new NodeOperation(op.value, nf, ns));
        }
    }
    
    if(nodes.get_size() != 1) {
        cout << init_idx << ' ' << last_idx << endl;
        throw NotFormattedTree("Não foi possível transformar a expressão em árvore ");
    }

    return nodes.see_front();
}

void Infixa::build(string exp) {
    int size = 0, open_p = 0;    
    {
        stringstream ss(exp); string s;
        while(ss >> s) {
            if(s == "(") open_p++;
            size++;
        }
            
    }

    string parts[size];
    
    {
        int i = 0;
        stringstream ss(exp); string s;
        while(ss >> s) parts[i++] = s;
    }


    try {
        head = recursion(parts, 0, 0, size-1, size);
    } catch(NotFormattedTree e) {
        cout << "TRATAMENTO NÃO IMPLEMENTADO." << endl;
    }
};