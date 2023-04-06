#include <sys/time.h>
#include <sys/resource.h>
#include <cmath>

#include "fibonacci.hpp"

typedef long long ll;

double calc_sen(double x, int n) {
  double sen = 0;
  for (int i = 0; i < n; i++) {
      sen += pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2 * i + 2);
  }
  return sen;
}

Fibonacci::Fibonacci() {};

OperationReturn Fibonacci::iterative(ll N) {
  struct rusage start, end;
  struct timespec start_clock, end_clock;

  getrusage(RUSAGE_SELF, &start);
  clock_gettime(CLOCK_MONOTONIC, &start_clock);

  ll last = 1, lastlast = 1, response = 1;
  for(int i = 2; i < N; i++) 
    response = last + lastlast, lastlast = last, last = response;

  getrusage(RUSAGE_SELF, &end);
  clock_gettime(CLOCK_MONOTONIC, &end_clock);

  return {response, get_user_time_exec(end, start), get_sys_time_exec(end, start), get_clock_time_exec(end_clock, start_clock)};
}

ll execution_fibonacci(ll N) {
  if(N == 1) return 1;
  if(N == 2) return 1;

  return execution_fibonacci(N-1) + execution_fibonacci(N-2);
}

OperationReturn Fibonacci::recursion(ll N) {
  struct rusage start, end;
  struct timespec start_clock, end_clock;

  getrusage(RUSAGE_SELF, &start);
  clock_gettime(CLOCK_MONOTONIC, &start_clock);

  ll response = execution_fibonacci(N);
  // calc_sen(2, (int)10e6);

  getrusage(RUSAGE_SELF, &end);
  clock_gettime(CLOCK_MONOTONIC, &end_clock);

  return {response, get_user_time_exec(end, start), get_sys_time_exec(end, start), get_clock_time_exec(end_clock, start_clock)};
}