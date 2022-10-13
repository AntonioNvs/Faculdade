#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N, L, R;

  cin >> N >> L >> R;

  vector<int> v(N);
  for(auto &i : v) cin >> i;

  sort(v.begin(), v.end());

  int tmin = 0, tmax = N-1;
  
  while(v[tmin] < L) tmin++;
  while(v[tmax] > R) tmax--;

  int dist = v[tmin] - L;
  for(int i = tmin+1; i <= tmax; i++)
    dist = max(dist, (v[i]-v[i-1])/2);

  dist = max(dist, R-v[tmax]);

  cout << dist << endl;

  return 0;
}