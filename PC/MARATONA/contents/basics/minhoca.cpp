#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N, M; cin >> N >> M;

  vector<int> lin(N, 0);
  vector<int> col(M, 0);

  int t;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) {
      cin >> t;
      lin[i]+=t, col[j]+=t;
    }

  int maxi = -1;
  for(int i = 0; i < N; i++)
    maxi = max(maxi, lin[i]);

  for(int j = 0; j < M; j++)
    maxi = max(maxi, col[j]);

  cout << maxi << endl;
  
  return 0;
}