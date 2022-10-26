#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  string w; cin >> w;

  int l = w.size();
  int ans = 0;

  for(int i = 0; i < l; i++) {
    if(w[i] == w[i+1]) {
      w.erase(i, 2);
      l = w.size();
      ans++, i = -1;
    }
  }
  cout << (ans % 2 == 1 ? "Yes" : "No") << endl;

  return 0;
}