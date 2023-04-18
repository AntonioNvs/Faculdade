#ifndef QUEUE
#define QUEUE

typedef struct CircularQueue {
  int *v;
  int front;
  int back;
  int size;
  int max_size;
} CircularQueue;

CircularQueue create_queue(int n);

CircularQueue insert(CircularQueue queue, int value);

int empty(CircularQueue queue);

int front(CircularQueue queue);

CircularQueue pop(CircularQueue queue);

void destroy(CircularQueue queue);

void print(CircularQueue queue);

#endif
