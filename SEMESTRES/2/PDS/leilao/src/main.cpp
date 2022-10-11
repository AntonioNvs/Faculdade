#include <iostream>

#include "Auction.hpp"
#include "Hurl.hpp"

using namespace std;

int main() {
    Auction leilao = Auction();

    int val, id;
    string str;
    char option;

    while(cin >> option) {
        switch(option) {
            // Adicionar uma pessoa
            case 'p':
                cin >> str;
                leilao.add_participant(str);
                break;
            // Adicionar um lance
            case 'h':
                cin >> str >> val >> id;
                leilao.add_hurl(str, val, id);
                break;
            // Adicionar um produto
            case 'o':
                cin >> val >> str;
                leilao.add_product(val, str);
                break;
            // Visualizar o ultimo lance de um produto
            case 'v':
                cin >> id;
                cout << "The person " << leilao.last_hurl_of_product(id).owner_name() << " made a " << leilao.last_hurl_of_product(id).get_value() << " offer!" << endl;
                break;
            // Vender um produto
            case 's':
                cin >> id;
                leilao.sold_product(id);
                break;
            // Sair
            default:
                return 0;
        }
        cout << endl;
    }
}