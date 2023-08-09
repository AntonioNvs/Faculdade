#include <iostream>
#include "order_algorithms.hpp"

OrderAlgorithms::OrderAlgorithms() {}

OrderAlgorithms::~OrderAlgorithms() {}

void OrderAlgorithms::sort(int *array, int size, std::string method, float gap) {    
    if (method == "heap") {
        this->heapSort(array, size);
    } else if (method == "shell") {
        this->shellSort(array, size, gap);
    }
}

void OrderAlgorithms::heapSort(int *array, int size) {
    int k = size / 2;

    while(k >= 0) {
        orderHeap(k, size, array);
        k--;
    }


    k = size;
    while(k >= 0) {
        std::swap(array[0], array[k-1]);
        k--;
        
        orderHeap(0, k, array);
    }
}

void OrderAlgorithms::orderHeap(int left, int right, int *array) {
    int father, child, x;

    father = left;
    child = 2*father + 1;

    x = array[father];

    while(child < right) {
        // Se o filho da direita for maior que o da esquerda, troca de importância
        if(child < (right-1) && array[child] < array[child + 1])
            child++;
        // Se o pai for maior que o maior filho, então não preciso verificar o resto pelo
        // silogismo hipotético
        
        if(x >= array[child])
            break;

        array[father] = array[child];
        father = child;
        child = 2*father + 1;
    }
    array[father] = x;
}

void OrderAlgorithms::shellSort(int *array, int size, float gap) {
    int i, j, value;
    int h = (float)size / gap;

    while(h > 0) {
        for(i = h; i < size; i++) {
            value = array[i];
            j = i;
            while(j > h-1 && value <= array[j-h]) {
                array[j] = array[j-h];
                j = j - h;
            }
            array[j] = value;
        }
        h = (float)h/gap;
    }
}