#include <stdio.h>
#include <stdlib.h>

void transform(float n, float *vl) {
  vl[0] = (int) n;
  vl[1] = n - vl[0];
}

int main() {
  system("cls");
  
  float v[2];

  transform(3.458575, v);
  
  printf("%.2f %f", v[0], v[1]);

  return 0;
}