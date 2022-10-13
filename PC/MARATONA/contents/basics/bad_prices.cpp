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
    int n; cin >> n;

    vector<int> arr(n, 0);
    vector<int> prefix(n, 0);

    for(auto &u : arr) cin >> u;

    prefix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
      prefix[i] = min(prefix[i+1], arr[i]);

    int ans = 0;
    for(int i = 0; i < n; i++)
      if(prefix[i] < arr[i]) ans++;

    cout << ans << endl;
  }
  return 0;
}