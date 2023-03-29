#ifndef FIBONACCIH
#define FIBONACCIH

#include "operation.hpp"

typedef long long ll;

class Fibonacci : public Operation {
  public:
    Fibonacci();
    virtual OperationReturn iterative(ll N);
    virtual OperationReturn recursion(ll N);
};

#endif