#pragma once

#include "Product.hpp"
#include "Hurl.hpp"
#include "Person.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Auction {
    public:
        // Construtor da classe
        Auction();

        // Adicionando participante
        Person add_participant(string name);
        
        // Adicionando produto
        Product add_product(int minimum, string descrip);

        // Adicionando um lance em um produto
        void add_hurl(string person_name, int val, int id);

        // Vendendo um produto e retornando nome da pessoa que ganhou
        string sold_product(int id);

        // Visualizar o último lance de um produto
        Hurl last_hurl_of_product(int id);

    private:    
        vector<Person> participants;
        vector<Product> products;
};