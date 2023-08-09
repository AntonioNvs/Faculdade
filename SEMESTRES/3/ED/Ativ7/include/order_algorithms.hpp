#ifndef ORDERALGORTIHMS_HPP
#define ORDERALGORTIHMS_HPP

#include <string>
#include "control_time.hpp"

class OrderAlgorithms {
    public:
        OrderAlgorithms();
        ~OrderAlgorithms();
        
        void sort(int *array, int size, std::string method, float gap = -1);
    private:
        void heapSort(int *array, int size);
        void orderHeap(int left, int right, int *array);
        void shellSort(int *array, int size, float gap);
};

#endif // ORDERALGORTIHMS_HPP