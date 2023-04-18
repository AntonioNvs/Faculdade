#include "stack.h"
#include "circular_queue.h"

#include <stdio.h>
#include <stdlib.h>

CircularQueue create_stack(int n) {
    return create_queue(n);
}

CircularQueue add_back(CircularQueue stack, int value) {
    return insert(stack, value);
}

int empty_stack(CircularQueue stack) {
    return empty(stack);
}

int top(CircularQueue stack) {
    CircularQueue aux = create_queue(stack.max_size);
    
    if(stack.size == 0) {
        printf("A pilha está vazia!");
        return -1;
    }
    
    while(stack.size > 1) {
        aux = insert(aux, front(stack));
        stack = pop(stack);
    }

    int top = front(stack);
    insert(aux, top);
    pop(stack);
    
    destroy(aux);

    return top;
}

CircularQueue pop_back(CircularQueue stack) {
    CircularQueue aux = create_queue(stack.max_size);
    
    if(stack.size == 0) {
        printf("A pilha está vazia!");
        return stack;
    }

    while(stack.size > 1) {
        aux = insert(aux, front(stack));
        stack = pop(stack);
    }
    
    destroy(stack);

    return aux;
}

void destroy_stack(CircularQueue stack) {
    free(stack.v);
}