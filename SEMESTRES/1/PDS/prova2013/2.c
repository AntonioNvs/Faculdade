#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 8

int aleatorio(int n) {
  return rand() % n;
}

void fillMatrix(int M[][N]) {
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      M[i][j] = aleatorio(2);
}

void printMatrix(int M[][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      printf("%d ", M[i][j]);
    printf("\n");
  }
}

int symmetryCheck(int M[][N]) {
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(M[i][j] != M[j][i])
        return 0;

  return 1;
}

int main() {
  int M[N][N], count = 0;

  do {
    fillMatrix(M);
    count ++;
  } while(!symmetryCheck(M));

  printMatrix(M);
  printf("Executions: %d\n", count);
}

