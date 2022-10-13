#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int T, D, M;

  cin >> T >> D >> M;

  vector<int> r(M);
  for(auto& u : r) cin >> u;

  r.push_back(D);
  int l = 0;
  bool can = false;
  for(int i = 0; i < r.size(); i++) {
    if(r[i]-l >= T) {
      can = true;
      break;
    }
    l = r[i];
  }
 
  if(can) cout << 'Y' << endl;
  else cout << 'N' << endl;

  return 0;
}