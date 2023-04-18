#ifndef STACK
#define STACK

#include "circular_queue.h"

CircularQueue create_stack(int n);

CircularQueue add_back(CircularQueue stack, int value);

int empty_stack(CircularQueue stack);

int top(CircularQueue stack);

CircularQueue pop_back(CircularQueue stack);

void destroy_stack(CircularQueue stack);


#endif