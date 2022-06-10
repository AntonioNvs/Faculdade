#include <stdio.h>
#include <stdlib.h>

void sum(int v1[], int v2[], int vsum[], int N) {
  for(int i = 0; i < N; i++) {
    vsum[i] = v1[i] + v2[i];
    printf("%d\n", vsum[i]);
  }
}

int main() {
  int N;

  int *v1;
  v1 = (int *) malloc(N*sizeof(int));

  int *v2;
  v2 = (int *) malloc(N*sizeof(int));

  int *v3;
  v3 = (int *) malloc(N*sizeof(int));

  scanf("%d", &N);

  for(int i = 0; i < N; i++)
    scanf("%d", &v1[i]);

  for(int i = 0; i < N; i++)
    scanf("%d", &v2[i]);

  sum(v1, v2, v3, N);
    

  free(v1);
  free(v2);
  free(v3);
  
  return 0;
}