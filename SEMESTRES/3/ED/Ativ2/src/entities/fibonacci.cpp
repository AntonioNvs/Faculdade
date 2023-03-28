#include "fibonacci.hpp"

typedef long long ll;

Fibonacci::Fibonacci() {};

ll Fibonacci::iterative(ll N) {
  if(N == 1) return 1;
  if(N == 2) return 2;

  ll last = 2, lastlast = 1, response;
  for(int i = 2; i < N; i++) 
    response = last + lastlast, lastlast = last, last = response;

  return response;
}

ll Fibonacci::recursion(ll N) {
  if(N == 1) return 1;
  if(N == 2) return 2;

  return recursion(N-1) + recursion(N-2);
}