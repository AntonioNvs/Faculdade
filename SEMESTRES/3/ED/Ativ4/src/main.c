#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

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
  
  int *randoms = generate_n_rand_numbers_of_mod(SIZE, 10);
  
  CircularQueue stack = create_stack(SIZE);

  printf("Empilhando a pilha com 10 números aleatórios.\n");

  for(int i = 0; i < SIZE; i++) {
    stack = add_back(stack, randoms[i]);
    printf("Empilhando %d\n", randoms[i]);
  }

  printf("\nDesempilhando a pilha..\n");

  while(stack.size) {
    int t = top(stack);
    printf("Desemplihando %d\n", t);
    stack = pop_back(stack);
  }

  destroy_stack(stack);
  free(randoms);
  return 0;
}