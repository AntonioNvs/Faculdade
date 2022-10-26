#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int t; cin >> t;

  while(t--) {
    ll N, h; cin >> N >> h;

    vector<ll> arr(N);
    for(auto &u : arr) cin >> u;

    sort(arr.begin(), arr.end());

    ll c;
    if(N >= 2) {
      c = 2*ceil((double)h / (double)(arr[N-1] + arr[N-2]));
      if(arr[N-1]*c/2 + arr[N-2]*c/2 - arr[N-2] >= h) c--;
    }
    else
      c = ceil((double)h / (double)arr[0]);

    cout << c << endl;
  }

  return 0;
}