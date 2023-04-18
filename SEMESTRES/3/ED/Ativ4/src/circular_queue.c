#include <stdio.h>
#include <stdlib.h>

#include "circular_queue.h"

CircularQueue create_queue(int n) {
  CircularQueue queue;
  queue.v = (int *)malloc(sizeof(int)*n);

  queue.max_size = n;
  queue.front = queue.back = queue.size = 0;
  return queue;
}

CircularQueue insert(CircularQueue queue, int value) {
  if(queue.size == queue.max_size) {
    printf("O tamanho da fila foi estourado!");
    return queue;
  }

  queue.v[queue.back] = value;
  queue.back = (queue.back + 1) % queue.max_size;

  queue.size++;

  return queue;
}

int empty(CircularQueue queue) {
  return queue.size == 0;
}

int front(CircularQueue queue) {
  if(empty(queue)) {
    printf("A fila está vazia!\n");
    return -1;
  }
  return queue.v[queue.front];
}

CircularQueue pop(CircularQueue queue) {
  if(empty(queue)) {
    printf("A fila está vazia!\n");
    return queue;
  }
  queue.front = (queue.front + 1) % queue.max_size;
  queue.size--;

  return queue;
}

void destroy(CircularQueue queue) {
  free(queue.v);
}

void print(CircularQueue queue) {
  for(int i = queue.front; i < queue.front + queue.size; i++) {
    int idx = i % queue.max_size;
    printf("%d ", queue.v[idx]);
  }
  printf("\n");
}