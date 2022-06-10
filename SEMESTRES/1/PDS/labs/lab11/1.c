#include <stdio.h>
#include <stdlib.h>

int sum(int v[], int idx, int N) {
  if(N == idx)
    return 0;

  return v[idx] + sum(v, idx+1, N);
}

int main() {
  int N;
  scanf("%d", &N);

  int v[N];

  for(int i = 0; i < N; i++)
    scanf("%d", &v[i]);

  printf("%d", sum(v, 0, N));
}