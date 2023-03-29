#include <string.h>
#include <iostream>

#include "fibonacci.hpp"
#include "factorial.hpp"

using namespace std;

int main(int argc, char ** argv) {
  
  char* operation = argv[1];
  int N = atoi(argv[2]);

  Fibonacci fibonacci = Fibonacci();
  Factorial factorial = Factorial();
  
  OperationReturn recursive, iterative;

  if(!strcmp("fibonacci", operation)) {
    recursive = fibonacci.recursion(N);
    iterative = fibonacci.iterative(N);
  }
  else if(!strcmp("factorial", operation)) {
    recursive = factorial.recursion(N);
    iterative = factorial.iterative(N);
  }
  printf("fat_recursive(%d): %lld with %lfs user time, %lfs system time and %lf clock time.\n", N, recursive.value, recursive.user_time, recursive.sys_time, recursive.clock_time);
  printf("fat_iterative(%d): %lld with %lfs user time, %lfs system time and %lf clock time.\n", N, iterative.value, iterative.user_time, iterative.sys_time, iterative.clock_time);
  
} 