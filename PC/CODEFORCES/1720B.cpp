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

    vector<int> arr(n);
    for(auto &u : arr) cin >> u;

    sort(arr.begin(), arr.end());

    cout << arr[n-1] + arr[n-2] - arr[0] - arr[1] << endl;
  }
  return 0;
}