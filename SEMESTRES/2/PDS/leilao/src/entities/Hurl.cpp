#include "Hurl.hpp"
#include "Person.hpp"

#include <string>

using std::string;

Hurl::Hurl(int val, Person *own) {
    value = val;
    owner = own;
}

string Hurl::owner_name() {
    return owner->get_name();
}

int Hurl::get_value() {
    return value;
}