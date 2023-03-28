#ifndef FACTORIALH
#define FACTORIALH
#include "operation.hpp"

typedef long long ll;

class Factorial : public Operation {
  public:
    Factorial();
    virtual ll iterative(ll N);
    virtual ll recursion(ll N);
};

#endif