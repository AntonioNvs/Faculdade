#include <string.h>
#include <iostream>

#include "fibonacci.hpp"
#include "factorial.hpp"

using namespace std;

int main(int argc, char ** argv) {
  
  string operation = argv[1];
  int N = atoi(argv[2]);

  Fibonacci fibonacci = Fibonacci();
  Factorial factorial = Factorial();
  
  OperationReturn recursive, iterative;

  if("fibonacci" == operation) {
    recursive = fibonacci.recursion(N);
    iterative = fibonacci.iterative(N);
  }
  else if("factorial" == operation) {
    recursive = factorial.recursion(N);
    iterative = factorial.iterative(N);
  }
  
  printf("%s recursive(%d): %lld with %.20gs user time, %.20gs system time and %.20gs clock time.\n", operation.c_str(), N, recursive.value, recursive.user_time, recursive.sys_time, recursive.clock_time);
  printf("%s iterative(%d): %lld with %.20gs user time, %.20gs system time and %.20gs clock time.\n", operation.c_str(), N, iterative.value, iterative.user_time, iterative.sys_time, iterative.clock_time);
  printf("\n");
  
  return 0;
} 