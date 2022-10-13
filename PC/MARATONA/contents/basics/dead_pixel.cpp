#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int T; cin >> T;

  while(T--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    cout << max(max((x)*b, (a-(x+1))*b), max((y)*a, (b-(y+1))*a)) << endl;
  }

  return 0;
}