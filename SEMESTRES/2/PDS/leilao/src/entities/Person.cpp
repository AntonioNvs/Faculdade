#include "Person.hpp"

#include <string>

using std::string;

Person::Person(string n) {
    name = n;
}

string Person::get_name() {
    return name;
}