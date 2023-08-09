/*
    Trabalho Prático - Estrutura de Dados - UFMG, operation.hpp
    Propósito: Definir estruturas de formatação para construção da 
    árvore na infixa e o nó geral abstrato da árvore

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#ifndef OPERATION
#define OPERATION

/*
    Formato de operador para construção da árvore na infixa
    @param value Char que representa a operação
    @param index Parâmetro único de identificação do operador
*/
struct OperatorFormat {
    char value;
    int index;
};

/*
    Formato abstrato do nó da árvore
    @param op Char indicando a operação
    @param value Valor da expressão até o nó de referência
    @param left Nó da esquerda
    @param right Nó da direita
*/
struct NodeOperation {
    char op;
    double value;
    NodeOperation* left = nullptr;
    NodeOperation* right = nullptr;

    NodeOperation() {};
    NodeOperation(double v) : value(v) {};
    NodeOperation(char o, NodeOperation* l, NodeOperation *r) : op(o), left(l), right(r) {};
};

/*
    Formato abstrato de nó para construção da árvore na Infixa
    @param value Nó indicando o valor
    @param index Valor único da operação que o nó está ligado
*/
struct NodeFormat {
    NodeOperation * value;
    int index;
};

#endif