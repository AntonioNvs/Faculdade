#include "queue.hpp"

template <typename T>
Queue<T>::Queue() {
    front = 0;
    back = 0;
    size = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete arr;
}

template <typename T>
bool Queue<T>::insert(T value) {
    if(size >= max_tam) return false;

    arr[back] = value;
    back = (back+1) % max_tam;
    size++;
    return true;
}

template <typename T>
int Queue<T>::get_size() {
    return size;
}

template <typename T>
bool Queue<T>::empty() {
    return size == 0;
}

template <typename T>
T Queue<T>::see_front() {
    return arr[front];
}

template <typename T>
void Queue<T>::pop_front() {
    front = (front + 1) % max_tam;
    size--;
}