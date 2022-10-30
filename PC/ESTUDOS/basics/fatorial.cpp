#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define MAXN 1000010
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef unsigned long long ll;

const ll MOD = 10e9;

ll memo[MAXN];

ll factorial(ll N) {
  if(N <= 1) return 1LL;
  if(memo[N] != -1) return memo[N];

  ll res = (N*factorial(N-1)) % MOD;

  while(res % 10 == 0) res /= 10;
  
  return memo[N] = res;
}

int main() { _
  ll N, k = 1;

  for(int i = 1; i <= MAXN; i++) memo[i] = -1LL;

  for(int i = 100; i <= MAXN; i += 1000) {
    factorial(i);
  }

  while(cin >> N) {
    ll f = factorial(N);

    cout << "Instancia " << k << endl;
    cout << f % 10 << endl;

    k++;
  }

  return 0;
}