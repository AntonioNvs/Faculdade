#ifndef FIBONACCIH
#define FIBONACCIH

#include "operation.hpp"

typedef long long ll;

class Fibonacci : public Operation {
  public:
    Fibonacci();
    virtual ll iterative(ll N);
    virtual ll recursion(ll N);
};

#endif