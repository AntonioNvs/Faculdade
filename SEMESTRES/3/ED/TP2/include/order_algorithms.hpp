/*
    Trabalho Prático - Estrutura de Dados - UFMG, order_algorithms.hpp
    Propósito: Definir estruturas gerais da classe OrderAlgorithms;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef ORDERALGORTIHMS_HPP
#define ORDERALGORTIHMS_HPP

#include <math.h> 
#include <iostream>

#include "adt/vector.hpp"

/*
    Classe que representa um conjunto de algoritmos de ordenação
*/
template <typename T>
class OrderAlgorithms {
    public:
        OrderAlgorithms();
        ~OrderAlgorithms();
        
        /*
            @brief Junta dois subvetores de um vetor
            @param Vetor de pontos
            @param Índice do primeiro elemento do primeiro subvetor
            @param Índice do último elemento do primeiro subvetor
            @param Índice do último elemento do segundo subvetor
        */
        void merge(T *array, int p, int q, int r);
        
        /*
            @brief Ordena um vetor de pontos
            @param Vetor de pontos
            @param Tamanho do vetor de pontos
            @param Método de ordenação
            @param Função de critério de ordenação
        */
        void sort(T *array, int size, std::string method, bool (*compare)(T, T));
    private:
        bool (*compare)(T, T);

        /*
            @brief Ordena um vetor de pontos utilizando o algoritmo merge sort
            @param Vetor de pontos
            @param Índice do primeiro elemento do vetor
            @param Índice do último elemento do vetor
        */
        void mergeSort(T *array, int l, int r);

        /*
            @brief Ordena um vetor de pontos utilizando o algoritmo insertion sort
            @param Vetor de pontos
            @param Tamanho do vetor de pontos
        */
        void insertionSort(T *array, int size);

        /*
            @brief Ordena um vetor de pontos utilizando o algoritmo linear sort
            @param Vetor de pontos
            @param Tamanho do vetor de pontos
        */
        void linearSort(T *array, int size);
};

template <typename T>
OrderAlgorithms<T>::OrderAlgorithms() {}

template <typename T>
OrderAlgorithms<T>::~OrderAlgorithms() {}

template <typename T>
void OrderAlgorithms<T>::sort(T *array, int size, std::string method, bool (*func)(T, T)) {
    compare = func;

    // Decidindo qual será o algoritmo a ser utilizado
    if (method == "merge") {
        this->mergeSort(array, 0, size-1);
    } else if (method == "insertion") {
        this->insertionSort(array, size);
    } else if (method == "linear") {
        this->linearSort(array, size);
    }
}

template <typename T>
void OrderAlgorithms<T>::merge(T *array, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Criando subvetores auxiliares
    T *L = new T[n1 + 1];
    T *R = new T[n2 + 1];

    for(int i = 0; i < n1; i++)
        L[i] = array[p + i];

    for(int j = 0; j < n2; j++)
        R[j] = array[q + j + 1];
    
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Agrupando os dois vetores em um ordenadamente
    while(i < n1 && j < n2) {
        if(this->compare(L[i], R[j])) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }

        k++;
    }

    // Pegando as sobras do primeiro subvetor
    while(i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Pegando as sobras do segundo subvetor
    while(j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    delete [] L;
    delete [] R;

}

template <typename T>
void OrderAlgorithms<T>::mergeSort(T *array, int l, int r) {
    // Ordenando o vetor recursivamente
    if(l < r) {
        int q = (l + r) / 2;

        this->mergeSort(array, l, q);
        this->mergeSort(array, q + 1, r);
        this->merge(array, l, q, r);
    }
}

template <typename T>
void OrderAlgorithms<T>::insertionSort(T *array, int size) {
    int i, j;
    T key;
    for(i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        // Movendo os elementos maiores que a chave para frente
        while(j >= 0 && this->compare(key, array[j])) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

template <typename T>
void OrderAlgorithms<T>::linearSort(T *points, int size) {
    // Aqui é considerado que será ordenado o tipo Point no algoritmo GRAHAM e somente nele.

    extern Point point_compare;

    // Criando os buckets
    const int num_buckets = size > 1000 ? 1000 : size;

    // O range é o tamanho do intervalo de cada bucket
    const double range = M_PI / num_buckets; 
    
    Vector<T> buckets[num_buckets];
    
    // Colocando os pontos nos buckets
    for(int i = 0; i < size; i++) {
        // Calculando o ângulo polar do ponto em relação ao ponto de comparação
        double angle = polarAngle(point_compare, points[i]);

        // Calculando o bucket que o ponto deve ser colocado
        int bucket = static_cast<int>(angle / range);
        buckets[bucket].push_back(points[i]);
    }

    // Ordenando os buckets
    for(int k = 0; k < num_buckets; k++) {
        if(buckets[k].get_size() > 100)
            mergeSort(buckets[k].begin(), 0, buckets[k].get_size()-1);
        else
            insertionSort(buckets[k].begin(), buckets[k].get_size());
    }

    int index = 0;
    // Colocando os pontos ordenados no vetor de pontos
    for(int k = 0; k < num_buckets; k++) {
        for(int i = 0; i < buckets[k].get_size(); i++) {
            points[index] = buckets[k][i];
            index++;
        }
    }
}

#endif // ORDERALGORTIHMS_HPP