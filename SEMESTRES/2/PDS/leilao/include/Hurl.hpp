#pragma once

#include "Person.hpp"

#include <string>

using std::string;

class Hurl {
    public:
        // Construtor
        Hurl(int val, Person *own);

        // Nome da pessoa que fez o lance
        string owner_name();

        // Valor do lance
        int get_value();
        
    private:
        int value;
        Person *owner;
};