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
    int N, q; cin >> N >> q;

    vector<int> arr(N);
    for(auto &u : arr) cin >> u;

    sort(arr.begin(), arr.end());
    vector<int> prefix(N+1);

    prefix[0] = 0;
    prefix[1] = arr[0];
    for(int i = 2; i <= N; i++) 
      prefix[i] = prefix[i-1] + arr[i-1];
    
    int a;
    while(q--) {
      cin >> a;
      if(a > prefix[N]) {
        cout << -1 << endl;
      } else if(a == prefix[N]) {
        cout << N << endl;
      } else {
        int rest = prefix[N] - a;
        
        cout << N-(lower_bound(prefix.begin(), prefix.end(), rest) - prefix.begin())+(binary_search(prefix.begin(), prefix.end(), rest) ? 0 : 1) << endl;
      }
    }
  }
  return 0;
}