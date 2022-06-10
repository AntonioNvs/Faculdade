#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, M;

  scanf("%d %d", &N, &M);

  int **v;
  v = (int **) malloc(N*sizeof(int*));

  for(int i = 0; i < N; i++) {
    v[i] = (int *)malloc(M * sizeof(int));

    for(int j = 0; j < M; j++) {
      scanf("%d", &v[i][j]);
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }

  free(v);
}