#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N;
  cin >> N;

  vector<pii> p(N);

  for(auto&u : p) cin >> u.first >> u.second;

  int cost = 0;
  int direction = -1;
  
  int gotted[N];
  memset(gotted, 0, sizeof(gotted));
  for(int i = 0; i < p.size(); i++) {
    if(gotted[i]) continue;

    gotted[i] = 1;

    direction = p[i].second;
    cost = max(cost, p[i].first) + 10;
    int aux = i+1;

    while(aux < N && p[aux].first < cost) {
      if(p[aux].second == direction) {
        cost = p[aux].first + 10;
        gotted[aux] = 1;
      }
      aux++;
    }
  }

  cout << cost << endl;

  return 0;
}