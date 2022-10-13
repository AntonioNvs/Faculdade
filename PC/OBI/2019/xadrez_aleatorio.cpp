#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int fatorial(int N) {
  int res = 1;
  for(int i = 2; i <= N; i++)
    res *= i;

  return res;
}

int main() { _
  int D, T;
  cin >> D >> T;

  if(T == 0)
    cout << D << endl;
  if(T == 1)
    cout << fatorial(D)/(fatorial(D-T-1)) << endl;
  if(T == 2) {
    ll ans = 0LL;
    for(int i = 1; i < D-1; i++)
      ans += i*(D-i-1);
    cout << ans << endl;
  }
  return 0;
}