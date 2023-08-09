/*
    Trabalho Prático - Estrutura de Dados - UFMG, queue.hpp
    Propósito: Definir estruturas gerais da classe Queue;

    @author Antônio Neves
    @version 1.0 21/04/2023
*/

#ifndef QUEUE
#define QUEUE

#define MAXTAMQUEUE 1010

struct EmptyQueue {
    std::string message;
    EmptyQueue(std::string msg) : message(msg) {};
};

/*
    Implementando uma fila circular
*/ 
template <typename T>
class Queue {
    public:
        Queue();
        ~Queue();

        /*
            @brief Olhando o elemento da frente da fila
            @return Primeiro elemento
        */
        T see_front();

        /*
            @brief Verificando se a fila está vazia ou não
            @return Boolean indicando a funcionalidade
        */
        bool empty();

        /*
            @brief Retorna o tamanho da fila
            @return Tamanho da fila
        */
        int get_size();

        /*
            @brief Inserindo um elemento na fila circular
            @param v Elemento a ser inserido
            @return Boolean indicando se foi possível inserir
        */
        bool insert(T v);

        /*
            @brief Removendo o elemento da frente da fila
        */
        void pop_front();

        void delete_pointers();

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
bool Queue<T>::insert(T value) {
    // Verificando se o tamanho da fila chegou ao máximo do array
    if(size >= max_tam) return false;

    arr[back] = value;
    // Aritmética modular para representar a circularidade da fila
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
    if(empty())
        throw EmptyQueue("A fila está vazia.");
        
    // Aritmética modular para representar a circularidade da fila
    front = (front + 1) % max_tam;
    size--;
}

template <typename T>
void Queue<T>::delete_pointers() {
    while(!empty()) {
        delete arr[front];
        pop_front();
    }
}

template <typename T>
Queue<T>::~Queue() {
    while(!empty())
        pop_front();
}

#endif