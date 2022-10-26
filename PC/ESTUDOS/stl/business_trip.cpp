#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int k; cin >> k;

  vector<int> arr(12);
  for(auto &u : arr) cin >> u;

  sort(arr.begin(), arr.end());

  int i = 11;
  while(k > 0 && i >= 0)
    k -= arr[i], i--;

  cout << (i >= 0 ? 11-i : (k <= 0) ? 12 : -1) << endl;

  return 0;
}