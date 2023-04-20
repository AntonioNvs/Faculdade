#include <sstream>
#include <string>

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
        else if(op == "/" || op == "x" || op == "-" || op == "+")
            { operations++; continue; }

        if(!is_digit(op)) return false;
        numbers++;
    } 

    return (open_p == close_p) && (numbers-1 == operations);
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

string Expression::replace_commons_to_dots(string str) {
    for(unsigned int i = 0; i < str.size(); i++) {
        int ascii = (int)(str[i]-'\0');
        if(ascii == 44) str[i] = '.';
    }

    return str;
}