#include "factorial.hpp"

typedef long long ll;

Factorial::Factorial() {}

ll Factorial::iterative(ll N) {
  ll crr = 2, response = 1;
  while(crr <= N)
    response *= crr++;

  return response;
}

ll Factorial::recursion(ll N) {
  if(N <= 1) return 1;

  return N*recursion(N-1);
}
