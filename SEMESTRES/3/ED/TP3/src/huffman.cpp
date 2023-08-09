#include <fstream>
#include <iostream>
#include <math.h>

#include "vector.hpp"
#include "huffman.hpp"
#include "control_time.hpp"
#include "priority_queue.hpp"

Huffman::Huffman(std::string input_filename, std::string output_filename, std::string mode, std::string treatment) {
    this->input_filename = input_filename;
    this->output_filename = output_filename;
    this->mode = mode;
    this->treatment = treatment;


    this->control_time = new ControlTime();
}

void delete_node(node_t<std::string> *node) {
    if(node == nullptr)
        return;

    delete_node(node->left);
    delete_node(node->right);

    delete node;
}

Huffman::~Huffman() {
    delete this->control_time;
    delete_node(this->root);
}

bool condition_accept(int c) {
    return (c < 65 || c > 90) && (c < 97 || c > 122);
}

bool condition_not_accept(int c) {
    return c == 32;
}

void Huffman::build_frequency_table() {
    FILE * file = fopen(this->input_filename.c_str(), "r");

    if(file == NULL)
        throw FileDoesNotExists();

    int r;
    char k;
    std::string line;
    // Lê o arquivo e conta a frequência de cada caracter
    while((r = fscanf(file, "%c", &k)) != 0) {
        if(k != '\n' && r != EOF) {
            int rep = (int)k;
            if(rep < 0 || rep > 127) {
                std::cout << "Algum caracter do input não é da tabela ASCII" << std::endl;
                throw CharNotASCII();
            }

            line += k;
            continue;
        }
        line += k;

        if(this->mode == "c") {
            for(long unsigned int i = 0; i < line.size(); i++) {
                std::string c = line.substr(i, 1);
                this->frequency_table[c]++;
            }
            if(r != EOF)
                this->frequency_table["\n"]++;
        } else {
            std::string word = "";
            
            for(long unsigned int i = 0; i < line.size(); i++) {
                int c = (int)line[i];
                if(this->treatment == "a" ? condition_accept(c) : condition_not_accept(c)) {
                    if(word.size() > 0) {
                        this->frequency_table[word]++;
                        word = "";
                    }
                    std::string add = " ";
                    add[0] = line[i];
                    
                    this->frequency_table[add]++;
                } else {
                    word += line[i];
                }
            }
            if(word.size() > 0) {
                this->frequency_table[word]++;
            }

            if(r != EOF)
                this->frequency_table["\n"]++;
        }
        if(r == EOF) break;
        line = "";
    }

    fclose(file);
}

bool compare_nodes(node_t<std::string> *a, node_t<std::string> *b) {
    return a->frequency > b->frequency;
}

void Huffman::build_huffman_tree() {
    PriorityQueue<node_t<std::string>*> queue = PriorityQueue<node_t<std::string>*>(compare_nodes);

    Vector<Map<std::string, long>::pair_t> arr = this->frequency_table.iterate();
    
    for(int i = 0; i < arr.get_size(); i++) {
        node_t<std::string> *node = new node_t<std::string>(arr[i].key, arr[i].value);
        queue.insert(node);
    }

    while(queue.get_size() > 1) {
        node_t<std::string> *left = queue.pop_front();
        node_t<std::string> *right = queue.pop_front();

        node_t<std::string> *node = new node_t<std::string>(NULL_HUFFMAN, left->frequency + right->frequency);
        
        node->left = left;
        node->right = right;

        queue.insert(node);
    }
    
    arr.delete_array();

    this->root = queue.pop_front();
}

void Huffman::build_huffman_table(node_t<std::string> *node, std::string code) {
    if(node->left == nullptr && node->right == nullptr) {
        this->huffman_table[node->value] = code;
        return;
    }

    this->build_huffman_table(node->left, code + "0");
    this->build_huffman_table(node->right, code + "1");
}

CompressReturn Huffman::compress() {
    this->control_time->start(CLOCK_MONOTONIC);
    Map<std::string, std::string> table;

    this->build_huffman_table(this->root, "");

    std::string line;
    long count_lines = 0;
    {
        std::ifstream input(this->input_filename);
        while(getline(input, line)) {
            count_lines++;
        }

    }
    line = "";
    FILE * input = fopen(this->input_filename.c_str(), "r");

    std::string extension = this->output_filename.substr(this->output_filename.find('.'), this->output_filename.size()- this->output_filename.find('.'));
    this->new_output = this->output_filename.substr(0, this->output_filename.find('.')) + this->get_mode() + extension;

    std::ofstream output(this->new_output, std::ios::out | std::ios::binary);

    if(input == NULL)
        throw FileDoesNotExists();
    
    long i = 0;
    long total = 0;
    long compacted = 0;
    this->num_bits = 0;

    char k;
    int r;
    std::string content = "";

    // Lê o arquivo e comprime
    while((r = fscanf(input, "%c", &k)) != 0) {
        if(k != '\n' && r != EOF) {
            line += k;
            continue;
        }
        i++;
        
        if(this->mode == "c") {
            // Se for o último caracter, não adiciona \n
            if(i <= count_lines && r != EOF)
                line += '\n';
            for(long unsigned int i = 0; i < line.size(); i++) {
                std::string c = line.substr(i, 1);
                long size = this->huffman_table[c].size();

                content += this->huffman_table[c];

                compacted += size;
                total += 8;
            }
        }
        else {
            std::string word = "";
            for(long unsigned int i = 0; i < line.size(); i++) {
                int c = line[i];
                // Verifica qual método de separação de palavras será utilizado
                if(this->treatment == "a" ? condition_accept(c) : condition_not_accept(c)) {
                    if(word.size() > 0) {
                        long size = this->huffman_table[word].size();
                        content += this->huffman_table[word];
                        compacted += size;
                        total += sizeof(char)*word.size()*8;
                        word = "";
                    }

                    std::string add = " ";
                    add[0] = line[i];
                    long size = this->huffman_table[add].size();
                    content += this->huffman_table[add];
                    compacted += size;
                    total += sizeof(char)*8;
                } else {
                    word += line[i];
                }
            }
            // Se a palavra não foi adicionada, adiciona
            if(word.size() > 0) {
                long size = this->huffman_table[word].size();
                content += this->huffman_table[word];
                compacted += size;
                total += sizeof(char)*word.size()*8;
            }

            // Se for o último caracter, não adiciona \n
            if(i <= count_lines && r != EOF) {
                long size = this->huffman_table["\n"].size();
                content += this->huffman_table["\n"];
                compacted += size;
                total += sizeof('\n')*8;
            }
        }

        if(r == EOF) break;
        line = "";
    }
    
    // Transforma os bits adquridos da árvore de Huffman em bytes
    for(unsigned int long k = 0; k < content.size(); k += 8) {
        char c = 0;
        for(int j = 0; j < 8; j++) {
            if(k+j < content.size()) {
                c = c << 1;
                if(content[k + j] == '1') c = c | 1;
            } else {
                c = c << 1;
            };
        }
        output.write(&c, sizeof(char));
    } 

    fclose(input);
    output.close();

    this->num_bits = content.size();

    this->control_time->stop(CLOCK_MONOTONIC);
    
    this->control_time->write_csv(this->num_bits, total, "compress", this->get_mode(), this->control_time->get_time());

    return {compacted, this->control_time->get_time().clock_time};
}

void Huffman::decompress() {
    this->control_time->start(CLOCK_MONOTONIC);
    std::ifstream output(this->input_filename, std::ios::out | std::ios::binary);
    std::ofstream descompacted(this->output_filename, std::ios::out | std::ios::binary);    

    char c;
    node_t<std::string> *crr = this->root;

    int count = 0;
    // Lê o arquivo e descomprime
    while(output.get(c)) {
        // Percorre a árvore de Huffman
        for(int i = 7; i >= 0; i--) {
            if(this->num_bits == count) {   
                output.close();
                descompacted.close();
                this->control_time->stop(CLOCK_MONOTONIC);
                this->control_time->write_csv(this->num_bits, count, "decompress", this->get_mode(), this->control_time->get_time());
                return;
            }
            char bit = ((c >> i) & 1) ? '1' : '0';

            if(bit == '0') crr = crr->left;
            else crr = crr->right;

            // Se for uma folha, escreve o caracter no arquivo
            if(crr->left == nullptr && crr->right == nullptr) {
                descompacted.write((&crr->value)->c_str(), sizeof(char)*(&crr->value)->size());
                crr = this->root;
            }
            count++;
        }
    }

    this->control_time->stop(CLOCK_MONOTONIC);
    this->control_time->write_csv(this->num_bits, count, "decompress", this->get_mode(), this->control_time->get_time());

    output.close();
    descompacted.close();
}

long Huffman::save_table(std::string tablefile) {
    this->control_time->start(CLOCK_MONOTONIC);
    Vector<Map<std::string, long int>::pair_t> arr = this->frequency_table.iterate();

    std::string type = this->get_mode();
    std::ofstream output(tablefile);

    output << type << "\n";
    output << this->num_bits << "\n";

    long count = 0;

    for(int i = 0; i < arr.get_size(); i++) {
        // Se for um espaço ou quebra de linha, salva como a representação deles
        std::string key = arr[i].key == " " ? this->space : (arr[i].key == "\n" ? this->linebroke : arr[i].key);
        output << key << " " << arr[i].value << "\n";
        count += key.size()*8 + log2(arr[i].value + 1)*8 + 8;
    }

    output.close();
    this->control_time->stop(CLOCK_MONOTONIC);
    this->control_time->write_csv(-1, count, "construct-table", type, this->control_time->get_time());

    arr.delete_array();

    return count;
}

void Huffman::read_table(std::string tablefile) {
    std::ifstream table(tablefile);
    
    if(!table.is_open()) {
        std::cout << "Tabela não existe" << std::endl;
        throw FileDoesNotExists();
    }

    long frequency;
    std::string line; getline(table, line);
    getline(table, line);

    this->num_bits = std::stoi(line);

    while(table >> line >> frequency)
        // Se for a representação do espaço ou da quebra de linha, salva como eles
        this->frequency_table[(line == this->space) ? " " : (line == this->linebroke ? "\n" : line)] = frequency;

    table.close();
}