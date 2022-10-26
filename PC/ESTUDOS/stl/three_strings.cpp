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
    string a, b, c;

    cin >> a >> b >> c;

    bool can = true;

    for(int i = 0; i < b.size(); i++)
      can &= (b[i] == c[i] || a[i] == c[i]);

    cout << (can ? "YES" : "NO") << endl;
  }

  return 0;
}