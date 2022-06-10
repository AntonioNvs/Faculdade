#include <stdio.h>
#include <stdlib.h>

void sum(int v[], int vsum[]) {
  
}

int main() {
  int N;
  scanf("%d", &N);

  int *v;
  v = (int *) malloc(N*sizeof(int));

  for(int i = 0; i < N; i++) {
    scanf("%d", &v[i]);
    printf("%d\n", v[i]);
  }

  free(v);
}