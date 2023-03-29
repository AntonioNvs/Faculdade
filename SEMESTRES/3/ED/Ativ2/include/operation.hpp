#ifndef OPERATIONH
#define OPERATIONH

#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>

typedef long long ll;

struct OperationReturn {
  ll value;
  double user_time;
  double sys_time;
  double clock_time;
};

class Operation {
  public:
    double get_sys_time_exec(rusage end, rusage start);
    double get_user_time_exec(rusage end, rusage start);
    double get_clock_time_exec(timespec end, timespec start);

    Operation();
    OperationReturn recursion(ll n);
    OperationReturn iterative(ll n);
};

#endif