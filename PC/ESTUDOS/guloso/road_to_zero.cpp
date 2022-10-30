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
    ll a, b, x, y; cin >> x >> y >> a >> b;

    ll ja = (x + y)*a;
    ll bt = b*min(x, y) + a*(x + y - 2*min(x, y));
    
    cout << min(bt, ja) << endl;
  }
  return 0;
}