#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N; cin >> N;

  vector<int> height(N);
  for(auto &u : height) cin >> u;

  int maxi = -1;
  for(int i = 0; i < N; i++) {
    int l = i-1, r = i+1;
    int kl = 1, kr = 1;
    int hl = height[i]-1, hr = height[i]-1;
    
    while(l >= 0 && hl > 0)
      hl = min(hl-1, height[l]-1), l--, kl++;

    while(r < N && hr > 0)
      hr = min(hr-1, height[r]-1), r++, kr++;

    maxi = max(maxi, min(kl, kr));
  }

  cout << maxi << endl;
  return 0;
}