#include <string.h>
#include <iostream>
#include <fstream>

#include "fibonacci.hpp"
#include "factorial.hpp"

using namespace std;

int main(int argc, char ** argv) {
  
  string operation = argv[1];
  int N = atoi(argv[2]);

  Fibonacci fibonacci = Fibonacci();
  Factorial factorial = Factorial();
  
  OperationReturn recursive, iterative;
  
  ofstream csv;
  csv.open("plots/" + operation + ".csv");

  csv << "n,rec_user,rec_sys,rec_clock,ite_user,ite_sys,ite_clock" << endl;

  for(int i = 1; i <= N; i ++) {
    if("fibonacci" == operation) {
      recursive = fibonacci.recursion(i);
      iterative = fibonacci.iterative(i);
    }
    else if("factorial" == operation) {
      recursive = factorial.recursion(i);
      iterative = factorial.iterative(i);
    }
    csv << i << ", " << 
        recursive.user_time << ", " <<
        recursive.sys_time << ", " <<
        recursive.clock_time << ", " <<
        iterative.user_time << ", " <<
        iterative.sys_time << ", " <<
        iterative.clock_time << endl;
  
    printf("%s recursive(%d): %lld with %.20gs user time, %.20gs system time and %.20gs clock time.\n", operation.c_str(), i, recursive.value, recursive.user_time, recursive.sys_time, recursive.clock_time);
    printf("%s iterative(%d): %lld with %.20gs user time, %.20gs system time and %.20gs clock time.\n", operation.c_str(), i, iterative.value, iterative.user_time, iterative.sys_time, iterative.clock_time);
    printf("\n");
  }

  csv.close();
  
  return 0;
} 