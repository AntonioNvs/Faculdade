#include "Hurl.hpp"
#include "Person.hpp"
#include "Auction.hpp"
#include "Product.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

Auction::Auction() {}

Person Auction::add_participant(string name) {
    Person part = Person(name);
    participants.push_back(part);
    return part;
}

Product Auction::add_product(int minimum, string descrip) {
    Product prod = Product(products.size(), minimum, descrip);
    products.push_back(prod);
    return prod;
}

void Auction::add_hurl(string person_name, int val, int id) {
    Person *part;
    for(int i = 0; i < participants.size(); i++)
        if(participants[i].get_name() == person_name)
            part = &participants[i];

    if(part == nullptr)
        return;

    products[id].add_hurl(val, part);
}

string Auction::sold_product(int id) {
    products[id].update_situation();
    return products[id].last_hurl().owner_name();
}

Hurl Auction::last_hurl_of_product(int id) {
    return products[id].last_hurl();
}
