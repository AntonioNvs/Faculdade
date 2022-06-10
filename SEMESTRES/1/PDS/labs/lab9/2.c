#include <stdio.h>
#include <stdlib.h>

void print_array(int v[], int N) {
  for(int i = 0; i < N; i++)
    printf("%d ", v[i]);
  printf("\n");
}

void multiply(int v[], int N, double x) {
  for(int i = 0; i < N; i++)
    v[i] *= x;
}

int main() {
  int N;
  scanf("%d", &N);

  int v[N];

  for(int i = 0; i < N; i++)
    scanf("%d", &v[i]);

  double x;
  scanf("%lf", &x);

  print_array(v, N);

  // all array multiply by the value
  multiply(v, N, x);

  print_array(v, N);

  // all array multiply by the 1 / value
  multiply(v, N, 1.0/x);

  print_array(v, N);
}