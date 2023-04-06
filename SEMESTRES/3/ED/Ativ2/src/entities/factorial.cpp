#include <sys/time.h>
#include <sys/resource.h>
#include <cmath>

#include "factorial.hpp"

typedef long long ll;

double calc_sin(double x, int n) {
  double sen = 0;
  for (int i = 0; i < n; i++) {
      sen += pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2 * i + 2);
  }
  return sen;
}

Factorial::Factorial() {}

OperationReturn Factorial::iterative(ll N) {
  struct rusage start, end;
  struct timespec start_clock, end_clock;

  getrusage(RUSAGE_SELF, &start);
  clock_gettime(CLOCK_MONOTONIC, &start_clock);

  ll crr = 2, response = 1;
  while(crr <= N)
    response *= crr++;

  getrusage(RUSAGE_SELF, &end);
  clock_gettime(CLOCK_MONOTONIC, &end_clock);

  return {response, get_user_time_exec(end, start), get_sys_time_exec(end, start), get_clock_time_exec(end_clock, start_clock)};
}


ll execution_factorial(ll N) {
    if(N <= 1) return 1;

    return (N)*execution_factorial(N-1);
}

OperationReturn Factorial::recursion(ll N) {
  struct rusage start, end;
  struct timespec start_clock, end_clock;

  getrusage(RUSAGE_SELF, &start);
  clock_gettime(CLOCK_MONOTONIC, &start_clock);

  ll response = execution_factorial(N);
  // calc_sin(2, (int)10e6);

  getrusage(RUSAGE_SELF, &end);
  clock_gettime(CLOCK_MONOTONIC, &end_clock);

  return {response, get_user_time_exec(end, start), get_sys_time_exec(end, start), get_clock_time_exec(end_clock, start_clock)};
}
