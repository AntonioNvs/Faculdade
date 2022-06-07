#include <stdio.h>
#include <stdlib.h>

int *num(int *n) {
  return n;
}
int main() {
  int *ptr;

  *ptr = 8;

  printf("%d", *num(ptr));
}