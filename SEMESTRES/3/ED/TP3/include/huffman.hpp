/*
    Trabalho Prático - Estrutura de Dados - UFMG, huffman.hpp
    Propósito: Definir estruturas gerais da classe Huffman;

    @author Antônio Neves
    @version 1.0 04/07/2023
*/

#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <string>

#include "map.hpp"
#include "control_time.hpp"

// Exceção para indicar a tentativa de acessar arquivos não existentes
struct FileDoesNotExists {};

// Exceção para indicar a tentativa de acessar caracteres não ASCII
struct CharNotASCII {};

const std::string NULL_HUFFMAN = "\0";

// Estrutura para armazenar os nós da árvore de Huffman
template <typename T>
struct node_t {
    T value;
    long frequency;
    node_t *left;
    node_t *right;
    
    // Construtores
    node_t() {
        this->value = NULL_HUFFMAN;
        this->left = nullptr;
        this->right = nullptr;
    };

    node_t(T c, long frequency) {
        this->value = c;
        this->frequency = frequency;
        this->left = nullptr;
        this->right = nullptr;
    };
};

// Estrutura para armazenar o retorno da função compress
struct CompressReturn {
    long count;
    double time;
};

// Classe para armazenar e manipular a codificação de Huffman
class Huffman {
    public:
        /*
            @brief Construtor da classe Huffman
            @param Nome do arquivo de entrada
            @param Nome do arquivo de saída
            @param Modo de execução (compressão ou descompressão)
            @param Tratamento de caracteres especiais (padrão ou alternativo)   
        */
        Huffman(std::string input_filename, std::string output_filename, std::string mode, std::string treatment = "a");
        ~Huffman();

        /*
            @brief Função para comprimir o arquivo de entrada
            @return Estrutura com o número de bits e o tempo de execução
        */
        CompressReturn compress();

        /*
            @brief Função para descomprimir o arquivo de entrada
        */
        void decompress();


        /*
            @brief Função para salvar a tabela de frequência em um arquivo
            @param Nome do arquivo de saída
            @return Número de bits escritos no arquivo
        */
        long save_table(std::string tablefile = "table.txt");

        /*
            @brief Função para ler a tabela de frequência de um arquivo
            @param Nome do arquivo de entrada
        */
        void read_table(std::string tablefile = "table.txt");

        /*
            @brief Função para construir a árvore de Huffman
        */
        void build_huffman_tree();

        /*
            @brief Função para construir a tabela de frequência
        */
        void build_frequency_table();

        /*
            @brief Função para adquirir o modo da classe
        */
        std::string get_mode() {
            return this->mode + this->treatment;
        }

        std::string new_output;
        
    private:
        Map<std::string, long> frequency_table = Map<std::string, long>();
        Map<std::string, std::string> huffman_table = Map<std::string, std::string>();

        node_t<std::string> *root = nullptr;
        long num_bits = 0;

        /*
            @brief Função para construir a tabela de Huffman
            @param Nó atual da árvore
            @param Código atual da árvore
        */
        void build_huffman_table(node_t<std::string>* node, std::string code); 

        // Representações dos caracteres de espaço e quebra de linha
        std::string space = "ç";
        std::string linebroke = "Ç";

        std::string input_filename;
        std::string output_filename;
        std::string mode;
        std::string treatment;

        ControlTime *control_time = nullptr;
};

#endif