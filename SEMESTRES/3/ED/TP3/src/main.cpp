#include <iostream>
#include <getopt.h>
#include <cstdio>

#include "map.hpp"
#include "vector.hpp"
#include "huffman.hpp"

#define MAX 0x3f3f3f3f

using namespace std;

int main(int argc, char* argv[]) {
    string mode = " "; mode[0] = argv[1][1];
    string in = argv[2];
    string out = argv[3];

    // Cada classe representa o módulo
    Huffman by_word_accept(in, out, "s");
    Huffman by_word_not(in, out, "s", "n");
    Huffman by_char(in, out, "c");

    string table_filename = "table.txt";

    if(mode == "c") {
        long word_not_bytes = MAX, word_accept_bytes = MAX, char_bytes = MAX;

        cout << "Compactando.." << endl;

        by_word_accept.build_frequency_table();
        by_word_not.build_frequency_table();
        by_char.build_frequency_table();

        by_word_accept.build_huffman_tree();
        by_word_not.build_huffman_tree();
        by_char.build_huffman_tree();

        CompressReturn cr = by_char.compress();
        cout << "Caracteres: " << cr.time << "s e " << cr.count/8 << " bytes" << endl;

        // Se o tempo de compressão for maior que 40s, não vale a pena verificar os outros modos
        if(cr.time > 25) {
            by_char.save_table(table_filename);
            rename(by_char.new_output.c_str(), out.c_str());
            return 0;
        }

        CompressReturn wnr = by_word_not.compress();
        cout << "Palavras por espaço: " << wnr.time << "s e " << wnr.count/8 << " bytes" << endl;

        CompressReturn war = by_word_accept.compress();
        cout << "Palavras por alfabeto: " << war.time << "s e " << war.count/8 << " bytes" << endl;

        word_not_bytes = wnr.count + by_word_not.save_table(table_filename);
        word_accept_bytes = war.count + by_word_accept.save_table(table_filename);
        char_bytes = cr.count + by_char.save_table(table_filename);

        // Verifica qual modo teve melhor compressão e salva ele
        if(word_accept_bytes <= min(word_not_bytes, char_bytes)) {
            by_word_accept.save_table(table_filename);
            rename(by_word_accept.new_output.c_str(), out.c_str());
        }
        else if(word_not_bytes < min(word_accept_bytes, char_bytes)) {
            by_word_not.save_table(table_filename);
            rename(by_word_not.new_output.c_str(), out.c_str());
        }
        else {
            by_char.save_table(table_filename);
            rename(by_char.new_output.c_str(), out.c_str());
        }

        // Remove os arquivos temporários
        remove(by_word_accept.new_output.c_str());
        remove(by_word_not.new_output.c_str());
        remove(by_char.new_output.c_str());
    } else {
        cout << "Descompactando por ";
        std::ifstream table(table_filename);

        if(!table.is_open())
            throw FileDoesNotExists();

        string fl; getline(table, fl);
        table.close();

        // Verifica qual modo foi compactado e descompacta
        if(fl[0] == 'c') {
            cout << "caracteres.." << endl;
            by_char.read_table(table_filename);
            by_char.build_huffman_tree();
            by_char.decompress();
        } else if(fl[1] == 'a') {
            cout << "palavras separadas se não for letra.." << endl;
            by_word_accept.read_table(table_filename);
            by_word_accept.build_huffman_tree();
            by_word_accept.decompress();
        } else {
            cout << "palavras separadas somente por espaço" << endl;
            by_word_not.read_table(table_filename);
            by_word_not.build_huffman_tree();
            by_word_not.decompress();
        }
    }
}