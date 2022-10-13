#include <bits/stdc++.h>

#define MAXN 10010
#define MAXK 10010
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int N, K, C;
int memo[MAXN][MAXK];
int v[MAXN];

int dp(int idx, int et) {
  if(idx > N)
    return -INF;
  if(idx == N && et != 0)
    return -INF;
  
  if(et == 0) {
    int s = 0;
    for(int i = idx; i < N; i++)
      s += v[i];
    return s;
  }

  if(memo[idx][et] != -INF)
    return memo[idx][et];

  return memo[idx][et] = max(dp(idx+C, et-1), dp(idx+1, et) + v[idx]);
}

int main() { _
  cin >> N >> K >> C;

  for(int i = 0; i < N; i++)
    for(int j = 0; j <= K; j++)
      memo[i][j] = -INF;

  for(int i = 0; i < N; i++)
    cin >> v[i];

  int ans = dp(0, K);
  cout << ans << endl;
  return 0;
}