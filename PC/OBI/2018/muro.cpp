#include <bits/stdc++.h>

#define MAXN 10010
#define MOD 1000000007LL
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

ll memo[MAXN];

ll dp(int x) {
  if(memo[x] != -1)
    return memo[x];

  return memo[x] = (dp(x-1) + dp(x-2)*4 + dp(x-3)*2) % MOD;
}

int main() { _
  memset(memo, -1, sizeof(memo));

  int N;
  cin >> N;

  memo[0] = 1LL;
  memo[1] = 1LL;
  memo[2] = 5LL;

  if(N == 0)
    cout << 1 << endl;
  else
    cout  << dp(N) << endl;
  return 0;
}