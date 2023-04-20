#ifndef QUEUE
#define QUEUE

#define MAXTAMQUEUE 1000

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

#endif