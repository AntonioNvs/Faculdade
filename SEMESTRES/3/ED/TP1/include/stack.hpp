#ifndef STACK
#define STACK
#define MAXTAMSTACK 1010

template <typename T>
class Stack {
    public:
        Stack();
        ~Stack();

        T top();
        bool empty();
        int get_size();
        bool insert(T v);
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
Stack<T>::~Stack() {}

template <typename T>
T Stack<T>::top() {
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
    if(size >= max_tam) {
        return false;
    }
    arr[back++] = value;
    size++;
    return true;
}

template <typename T>
void Stack<T>::pop() {
    if(back == 0) return;
    back--, size--;
}

#endif