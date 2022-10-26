#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

bool compare(pii a, pii b) {
  return a.first < b.first;
}

int main() { _
  int t, i = 1; cin >> t;

  while(t--) {
    int N, C; cin >> C >> N;

    vector<pii> arr(N);
    for(int i = 1; i <= N; i++) {
      int v; cin >> v;
      arr[i-1] = {v, i};
    }
    
    sort(arr.begin(), arr.end(), compare);

    int l = 0, r = N-1;

    while(l < r) {
      if(arr[l].first + arr[r].first == C) break;
      if(arr[l].first + arr[r].first > C) r--;
      else l++;
    }
    cout << "Caso #" << i << ": " << min(arr[l].second, arr[r].second) << ' ' << max(arr[l].second, arr[r].second) << endl;

    i++;
  }
  return 0;
}