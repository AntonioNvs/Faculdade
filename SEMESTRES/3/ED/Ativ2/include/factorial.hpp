#ifndef FACTORIALH
#define FACTORIALH
#include "operation.hpp"

typedef long long ll;

class Factorial : public Operation {
  public:
    Factorial();
    virtual OperationReturn iterative(ll N);
    virtual OperationReturn recursion(ll N);
};

#endif