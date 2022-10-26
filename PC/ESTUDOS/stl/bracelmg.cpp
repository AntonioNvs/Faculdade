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
    string p, b;
    cin >> p >> b;

    bool exists = false;
    for(int i = 0; i < b.size(); i++) {
      bool is = true;
      for(int j = 0; j < p.size(); j++) {
        int idx1 = (i+j) % b.size();
        int idx2 = (i-j >= 0 ? i-j : b.size()+i-j);

        if(b[idx1] != p[j] && b[idx2] != p[j]) {
          is = false;
          break;
        }
      }

      if(is) {
        exists = true;
        break;
      }
    }

    cout << (exists ? 'S' : 'N') << endl; 
  }
  return 0;
}