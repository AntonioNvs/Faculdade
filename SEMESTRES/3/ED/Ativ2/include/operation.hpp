#ifndef OPERATIONH
#define OPERATIONH

#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>

typedef long long ll;

struct OperationReturn {
  ll value;
  float user_time;
  float sys_time;
  float clock_time;
};

class Operation {
  public:
    float get_sys_time_exec(rusage end, rusage start);
    float get_user_time_exec(rusage end, rusage start);
    float get_clock_time_exec(timespec end, timespec start);

    Operation();
    OperationReturn recursion(ll n);
    OperationReturn iterative(ll n);
};

#endif