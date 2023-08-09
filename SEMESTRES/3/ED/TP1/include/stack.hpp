/*
    Trabalho Prático - Estrutura de Dados - UFMG, stack.hpp
    Propósito: Definir estruturas gerais da classe Stack;

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#ifndef STACK

#include <iostream>
#define STACK
#define MAXTAMSTACK 1010

struct EmptyStack {
    std::string message;
    EmptyStack(std::string msg) : message(msg) {};
};

// Implementando a estrutura de dados Pilha
template <typename T>
class Stack {
    public:
        Stack();
        ~Stack();

        /*
            Retorna o elemento do topo da pilha
            @return Elemento do topo
        */
        T top();

        /*
            Retorna se a pilha está vazia ou não
            @return 
        */
        bool empty();

        /*
            Retorna o tamanho da pilha
            @return Tamanho da pilha
        */
        int get_size();

        /*
            Insere o elemento dado como parâmetro na pilha
            @param v Elemento a ser inserido
            @return Retorna se foi possível ou não adicionar o elemento
        */
        bool insert(T v);

        /*
            Remove o elemento do topo da pilha
        */
        void pop();
    private:
        int back;
        int size;
        T arr[MAXTAMSTACK];
        int max_tam = MAXTAMSTACK;
};

template <typename T>
Stack<T>::Stack() {
    size = 0;
    back = 0;
}

template <typename T>
Stack<T>::~Stack() {
    while(!empty())
        pop();
}

template <typename T>
T Stack<T>::top() {
    // Caso não existe um elemento na pilha, retorne a forma
    // padrão da tipagem
    if(!back) {
        return T();
    }
    return arr[back-1];
}

template <typename T>
bool Stack<T>::empty() {
    return get_size() == 0;
}

template <typename T>
int Stack<T>::get_size() {
    return size;
}

template <typename T>
bool Stack<T>::insert(T value) {
    // Retorna false caso o tamanho da pilha for superfaturado
    if(size >= max_tam) {
        return false;
    }
    arr[back++] = value;
    size++;
    return true;
}

template <typename T>
void Stack<T>::pop() {
    if(back == 0)
        throw EmptyStack("A fila está vazia.");
    back--, size--;
}

#endif