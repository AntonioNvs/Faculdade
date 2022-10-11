#pragma once

#include <string>
#include <vector>

#include "Hurl.hpp"
#include "Person.hpp"

using std::string;
using std::vector;

class Product {
    public:
        // Construtor
        Product(int id_, int minim, string descrip);

        // Retornando o id
        int get_id();

        // Retornando a situação    
        bool get_situation();

        // Retornando a descrição
        string get_description();

        // Adicionando um lance, com a condição de que tem que ser maior que o último
        void add_hurl(int val, Person * own);
        
        // Visualizando o último lance
        Hurl last_hurl();

       // Atualizando o estado
       void update_situation();

    private:
        int id;
        bool sold;
        int minimum;
        string description;
        vector<Hurl> bids;
};