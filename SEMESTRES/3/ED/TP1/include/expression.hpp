/*
    Trabalho Prático - Estrutura de Dados - UFMG, expression.hpp
    Propósito: Definir estruturas gerais da classe Expression e definir structs de erros;

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>
#include "operation.hpp"


/* 
    @brief Estrutrua de erro para quando a árvore não for construída da forma correta
    @param message Mensagem de erro específica  
*/
struct NotFormattedTree {
    std::string message;
    NotFormattedTree(std::string msg) : message(msg) {};
};

/*
    @brief Estrutura de erro para divisões por zero no caminhamento da árvore
    @param message Mensagem de erro específica
*/
struct DivisionByZero {
    std::string message;
    DivisionByZero(std::string msg) : message(msg) {};
};

class Expression {
    public:
        Expression();
        virtual ~Expression();
        
        /*
            @brief Retorna se a string dada como parâmetro é um número real
            @param str String para ser analisada
            @return se é um número real ou não
        */
        bool is_digit(std::string str);

        /*
            @brief Retorna se a expressão numérica é válida
            @param exp string da expressão
            @return boolean indicando se é válido ou não
        */
        bool validate(std::string exp);

        /*
            @brief Retorna o atributo privado que indica se a expressão 
            guardado na classe é válida ou não
            @return boolean o valor da variável privada validated
        */
        bool is_valid() { return validated; };

        /*
            @brief Identifica qual expressão é a que está armazenada
            @return retorna 'p' para pósfixa e 'i' para infixa
        */
        char identify_type_of_expression();

        /*
            @brief Atribui o novo valor a variável validated
            @param valid Novo valor booleano
        */
        void set_valid(bool valid) { validated = valid; }
        
        /*
            @brief Retorna a expressão armazenada na classe
            @return string significando a expressão
        */
        std::string get_expression() { return sentence; }

        /*
            @brief Atribui o cache privado da expressão na classe
            @param expressão a ser salva
        */
        void set_expression(std::string line) { sentence = line; }

        /*
            @brief Função que caminha na árvore armazenada em busca de calcular
            o valor da expressão
            @return valor final encontrado
        */
        double solve();

        /*
            @brief Caso a expressão tenha vírgulas ao invés de pontos, é feito o
            'replace'
            @param str expressão como referência
        */
        void replace_commons_to_dots(std::string &str);
        
        /*
            @brief Imprime os elementos da árvore em pós-ordem
        */
        void post_order();

        /*
            @brief Imprime os elementos da árvore em in-ordem
        */
        void in_order();
        
        /*
            @brief Função a ser declarada pelas classes filhas de construção
            da árvore;
            @param exp expressão na qual será a base da construção da árvore
        */

        /*
            @brief Exclui todos os nós da árvore
            @param root Nó a ser excluído
        */
        void exclude_tree(NodeOperation* root);

        virtual void build(std::string exp) { return; };
    protected:
        // Nó cabeça da árvore
        NodeOperation* head = nullptr;
    private:
        std::string sentence;
        bool validated = false;
};

#endif