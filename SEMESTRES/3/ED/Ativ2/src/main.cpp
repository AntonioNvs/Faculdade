#include <string.h>
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>

#include "fibonacci.hpp"
#include "factorial.hpp"

using namespace std;

int main(int argc, char ** argv) {
  char* operation = argv[1];
  int N = atoi(argv[2]);

  Fibonacci fibonacci = Fibonacci();
  Factorial factorial = Factorial();

  if(!strcmp("fibonacci", operation)) {
    cout << "Recursive: " << fibonacci.recursion(N) << endl;
    cout << "Iterative: " << fibonacci.iterative(N) << endl;
  }
  else if(!strcmp("factorial", operation)) {
    cout << "Recursive: " << factorial.recursion(N) << endl;
    cout << "Iterative: " << factorial.iterative(N) << endl;
  }
} 