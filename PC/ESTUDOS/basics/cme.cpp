#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
/*
  I + I = II - 4
  II + I = III - 6
  III + I = IIII - 8
*/
  int q; cin >> q;

  while(q--) {
    int n; cin >> n;

    if(n < 4) cout << 4-n << endl;
    else cout << n % 2 << endl;
    
  }
  return 0;
}