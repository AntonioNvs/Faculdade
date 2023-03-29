#include <sys/time.h>
#include <sys/resource.h>

#include "fibonacci.hpp"

typedef long long ll;

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

  getrusage(RUSAGE_SELF, &end);
  clock_gettime(CLOCK_MONOTONIC, &end_clock);

  return {response, get_user_time_exec(end, start), get_sys_time_exec(end, start), get_clock_time_exec(end_clock, start_clock)};
}