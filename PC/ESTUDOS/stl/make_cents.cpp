#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int t; cin >> t;

  cout << setprecision(6) << fixed;

  while(t--) {
    int c, n; cin >> c >> n;
    map<string, float> curr;
    curr["JD"] = 1.0;

    string w; float v;
    while(c--) {
      cin >> w >> v;
      curr[w] = v;
    }

    float total = 0.0;
    
    while(n--) {
      cin >> v >> w;
      total += v*curr[w];
    }

    cout << total << endl;
  }
  return 0;
}