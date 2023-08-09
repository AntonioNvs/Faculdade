/*
    Trabalho Prático - Estrutura de Dados - UFMG, vector.hpp
    Propósito: Definir estruturas gerais da classe Vector;

    @author Antônio Neves
    @version 1.0 04/07/2023
*/

#ifndef VECTOR
#define VECTOR

#include <iostream>

/*
    Implementando uma lista dinâmica na qual possui métodos
    auxiliares
*/
template <typename T>
class Vector {
    public:
        Vector();
        ~Vector();

        /*
            @brief Adicionando o elemento ao final do vector
            @param Elemento a ser adicionado
        */
        void push_back(T element);

        /*
            @brief Removendo o último elemento do vector
        */
        void pop_back();
        
        /*
            @brief Retorna o último elemento do vector
            @return Último elemento do vector
        */
        T top();

        /*
            @brief Retorna o ponteiro para o primeiro elemento do vector
            @return Ponteiro para o primeiro elemento do vector
        */
        T* begin();

        /*
            @brief Retorna o ponteiro para o último elemento do vector
            @return Ponteiro para o último elemento do vector
        */
        T* end();
        
        /*
            @brief Sobrecarga do operador []
            @param Índice do elemento a ser acessado
            @return Elemento do vector
        */
        T& operator[](int index);

        /*
            @brief Retorna o tamanho do vector
            @return Tamanho do vector
        */
        int get_size(); 

        void delete_array();

    private:
        // Capacidade inicial do vector
        int capacity = 1010;

        // Ponteiro para o array
        T *array;

        // Tamanho do vector
        int size;
};

template <typename T>
Vector<T>::Vector() {
    // Inicializando o array com a capacidade inicial
    this->size = 0;
    this->array = new T[this->capacity];
}

template <typename T>
Vector<T>::~Vector() {
    // Deletando o array
}

template <typename T>
void Vector<T>::delete_array() {
    delete[] this->array;
}

template <typename T>
T Vector<T>::top() {
    // Se o vector estiver vazio, retorna um elemento nulo
    if(size == 0) return T();

    // Retorna o último elemento do vector
    return this->array[this->size-1];
}

template <typename T>
T* Vector<T>::begin() {
    return &(this->array[0]);
}

template <typename T>
T* Vector<T>::end() {
    return &(this->array[this->size-1]);
}

template <typename T>
void Vector<T>::push_back(T element) {
    // Se o vector estiver cheio, duplica a capacidade
    if(this->size == this->capacity) {
        this->capacity *= 2;
        T *new_array = new T[this->capacity];

        // Copiando os elementos do array antigo para o novo
        for(int i = 0; i < this->size; i++)
            new_array[i] = this->array[i];

        delete[] this->array;
        this->array = new_array;
    }
    
    // Adicionando o elemento ao final do vector
    this->array[this->size++] = element;
}

template <typename T>
void Vector<T>::pop_back() {
    this->size--;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    return this->array[index];
}

template <typename T>
int Vector<T>::get_size() {
    return this->size;
}

#endif