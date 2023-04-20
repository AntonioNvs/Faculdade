#include <sstream>
#include <string>

#include "operation.hpp"
#include "expression.hpp"

using namespace std;

Expression::Expression() {}

Expression::~Expression() {}

bool Expression::validate(string exp) {
    stringstream ss(exp);

    string op;
    int open_p = 0, close_p = 0, operations = 0, numbers = 0;
    while(ss >> op) {
        if(op == "(")
            { open_p++; continue; }
        else if(op == ")")
            { close_p++; continue; }
        else if(op == "/" || op == "*" || op == "-" || op == "+")
            { operations++; continue; }

        if(!is_digit(op)) return false;
        numbers++;
    } 

    return validated = (open_p == close_p) && (numbers-1 == operations);
}

bool Expression::is_digit(string str) {
    bool just_zeros = true;
    for(unsigned int i = 0; i < str.size(); i++) {
        char c = str[i];
        int ascii = (int)(c - '\0');

        if(ascii < 44 || ascii > 57) return false;
        just_zeros &= ascii == 48;
    } 
    double result = atof(str.c_str());

    if(result == 0 && !just_zeros) return false;

    return true;
}


char Expression::identify_type_of_expression() {
    stringstream ss(sentence); string p;
    while(ss >> p);

    if(p == "+" || p == "-" || p == "*" || p == "/") 
        return 'p';
    return 'i';
}

void Expression::replace_commons_to_dots(string &str) {
    for(unsigned int i = 0; i < str.size(); i++) {
        int ascii = (int)(str[i]-'\0');
        if(ascii == 44) str[i] = '.';
    }
}

double solve_recursive(NodeOperation *root) {
    if(root->left == nullptr && root->right == nullptr) return root->value;
    if(root->op == '+')
        return root->value = solve_recursive(root->left) + solve_recursive(root->right);
    if(root->op == '*')
        return root->value = solve_recursive(root->left) * solve_recursive(root->right);
    if(root->op == '-')
        return root->value = solve_recursive(root->left) - solve_recursive(root->right);
    if(root->op == '/')
        return root->value = solve_recursive(root->left) / solve_recursive(root->right);

    return 0;
}

double Expression::solve() {
    return solve_recursive(head);
}

void go_through_post_order(NodeOperation *root) {
    if(root != nullptr) {
        go_through_post_order(root->left);
        go_through_post_order(root->right);
        
        if(!root->left && !root->right) cout << root->value << ' ';
        else cout << root->op << ' ';
    }
}

void Expression::post_order() {
    go_through_post_order(head);
}

void go_through_in_order(NodeOperation *root) {
    if(root != nullptr) {
        bool is_digit = !root->left && !root->right;
        
        if(!is_digit) cout << "( ";

        go_through_in_order(root->left);
        if(!root->left && !root->right)
        cout << root->value << ' ';
        else cout << root->op << ' ';
        go_through_in_order(root->right);
        
        if(!is_digit) cout << ") ";
    }
}

void Expression::in_order() {
    go_through_in_order(head);
}