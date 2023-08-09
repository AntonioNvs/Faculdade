/*
    Trabalho Prático - Estrutura de Dados - UFMG, priority_queue.hpp
    Propósito: Definir estruturas gerais da classe PriorityQueue;

    @author Antônio Neves
    @version 1.0 04/07/2023
*/

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include "vector.hpp"
#include <iostream>

// Exceção para indicar a tentativa de acessar uma fila de prioridade vazia
struct EmptyPriorityQueue {
    EmptyPriorityQueue() {}
};

template <typename T>
class PriorityQueue {
    public:
        /*
            @brief Construtor da classe PriorityQueue
            @param Função de comparação
        */
        PriorityQueue(bool (*func)(T, T));

        /*
            @brief Destrutor da classe PriorityQueue
        */
        ~PriorityQueue() {
            arr.delete_array();
        }
        
        /*
            @brief Retorna o elemento de maior prioridade
            @return Elemento de maior prioridade
        */
        T& front();
        
        /*
            @brief Insere um elemento na fila de prioridade
            @param Elemento a ser inserido
        */
        void insert(const T&value);

        /*
            @brief Remove o elemento de maior prioridade
            @return Elemento de maior prioridade
        */
        T pop_front();

        /*
            @brief Retorna o tamanho da fila de prioridade
            @return Tamanho da fila de prioridade
        */
        int get_size();

    private:
        // Função de comparação
        bool (*compare)(T, T);

        Vector<T> arr;
        int size;

        /*
            @brief Retorna o índice do pai de um elemento
            @param Índice do elemento
            @return Índice do pai do elemento
        */
        int parent(int i);

        /*
            @brief Retorna o índice do filho esquerdo de um elemento
            @param Índice do elemento
            @return Índice do filho esquerdo do elemento
        */
        int left_child(int i);

        /*
            @brief Retorna o índice do filho direito de um elemento
            @param Índice do elemento
            @return Índice do filho direito do elemento
        */
        int right_child(int i);
};

template <typename T>
PriorityQueue<T>::PriorityQueue(bool (*func)(T, T)) {
    compare = func;
    this->size = 0;
}

template <typename T>
T& PriorityQueue<T>::front() {
    return this->arr[0];
}

template <typename T>
int PriorityQueue<T>::get_size() {
    return size;
}

template <typename T>
void PriorityQueue<T>::insert(const T&value) {
    this->arr.push_back(value);
    this->size++;
    int i = this->size - 1;
    if(i == 0)
        arr[0] = value;
    
    // Sobe o elemento até a posição correta
    while(i != 0 && compare(this->arr[parent(i)], this->arr[i])) {
        std::swap(this->arr[i], this->arr[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
T PriorityQueue<T>::pop_front() {
    if(this->size == 0) throw EmptyPriorityQueue();
    if(this->size == 1) {
        this->size--;
        return this->arr[0];
    }

    T root = this->arr[0];
    this->arr[0] = this->arr[this->size - 1];
    this->size--;

    this->arr.pop_back();
    int i = 0;
    // Desce o elemento até a posição correta
    while(i < this->size) {
        int largest = i;
        if(left_child(i) < this->size && compare(this->arr[largest], this->arr[left_child(i)]))
            largest = left_child(i);
        if(right_child(i) < this->size && compare(this->arr[largest], this->arr[right_child(i)]))
            largest = right_child(i);
        if(largest != i) {
            std::swap(this->arr[i], this->arr[largest]);
            i = largest;
        } else break;
    }
    return root;
}

template <typename T>
int PriorityQueue<T>::parent(int i) {
    return (i - 1) / 2;
}

template <typename T>
int PriorityQueue<T>::left_child(int i) {
    return (2 * i) + 1;
}

template <typename T>
int PriorityQueue<T>::right_child(int i) {
    return (2 * i) + 2;
}

#endif