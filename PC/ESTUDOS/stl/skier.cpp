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
    string o; cin >> o;

    map<pii, map<pii, int>> h;

    int x = 0, y = 0;
    int ans = 0;
    pii curr = {0, 0};

    for(int i = 0; i < o.size(); i++) {
      if(o[i] == 'N') y++;
      else if(o[i] == 'S') y--;
      else if(o[i] == 'W') x--;
      else x++;
      
      pii next = {x, y};
      ans += (h[next][curr] ? 1 : 5);
      h[next][curr] = 1;
      h[curr][next] = 1;
      curr = next;
    }

    cout << ans << endl;
  }
  return 0;
}