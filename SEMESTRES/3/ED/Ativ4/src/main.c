#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "circular_queue.h"

int * generate_n_rand_numbers_of_mod(int n, int mod) {
  /* 
    Criando N números aleatórios de 1 a mod, sem repetição, logo,
    mod deve ser maior ou igual a n
  */

  int *v = (int*)malloc(sizeof(int)*n);
  for(int i = 0; i < n; i++)
    v[i] = -1;
  
  if(mod < n) {
    printf("O valor de mod deve ser maior que n\n");
    return v;
  }

  int i = 0, not_exists;
  while(i < n) {
    while(1) {
      int rn = (rand() % mod) + 1;
      not_exists = 1;
      for(int j = 0; j <= i; j++)
        if(v[j] == rn)
          not_exists = 0;
      
      if(not_exists) {
        v[i] = rn;
        break;
      }
    }
    i++;
  }

  return v;
}

int main() {
  const int SIZE = 10;
  srand(time(NULL));
  
  int *v = generate_n_rand_numbers_of_mod(SIZE, 10);

  CircularQueue *queue = create_queue(SIZE);
  
  printf("%d %d %d %d\n", queue->back, queue->front);

  for(int i = 0; i < SIZE; i++)
    insert(queue, v[i]);

  print(queue);

  return 0;
}