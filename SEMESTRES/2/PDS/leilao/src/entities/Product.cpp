#include "Product.hpp"
#include "Hurl.hpp"
#include "Person.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

Product::Product(int id_, int minim, string descrip) {
    id = id_;
    minimum = minim;
    description = descrip;
    sold = false;
}

int Product::get_id() {
    return id;
}

string Product::get_description() {
    return description;
}

bool Product::get_situation() {
    return sold;
}

Hurl Product::last_hurl() {
    if(bids.empty())
        return Hurl(0, nullptr);
    return bids.back();
}

void Product::add_hurl(int val, Person *own) {
    Hurl bid = Hurl(val, own);

    if(val > last_hurl().get_value())
        bids.push_back(bid);
}

void Product::update_situation() {
    sold = true;
}