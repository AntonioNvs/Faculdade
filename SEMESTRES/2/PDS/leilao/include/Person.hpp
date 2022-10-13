#pragma once

#include <string>

using std::string;

class Person {
    public:
        // Construtor da classe
        Person(string n);

        // Getter do name
        string get_name();
        
    private:
        string name;
};