#ifndef QUEUE
#define QUEUE

#define MAXTAMQUEUE 1010

// Implementando uma fila circular
template <typename T>
class Queue {
    public:
        Queue();
        ~Queue();

        T see_front();
        bool empty();
        int get_size();
        bool insert(T v);
        void pop_front();
    private:
        int front;
        int back;
        int size;
        int max_tam = MAXTAMQUEUE;
        T arr[MAXTAMQUEUE];
};

template <typename T>
Queue<T>::Queue() {
    front = 0;
    back = 0;
    size = 0;
}

template <typename T>
Queue<T>::~Queue() {}

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

#endif