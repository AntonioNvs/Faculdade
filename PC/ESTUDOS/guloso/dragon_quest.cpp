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
    int H, N, M; cin >> H >> N >> M;

    while(N && H > 0) {
      int abs = H/2 + 10;
      if(abs >= H) break;
      H = abs, N--;
    }

    while(M && H > 0) {
      int light = H-10;
      H = light, M--;
    }
    
    cout << (H <= 0 ? "YES" : "NO") << endl;
  }

  return 0;
}