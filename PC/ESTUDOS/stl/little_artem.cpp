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
    int n, m; cin >> n >> m;
    /*
    even  odd
    B      B
    W     *W*
   *B*

   n*m is odd (5*5)
   BWBWB
   BWBWW
   BWBWB
   BWBWW
   BWBWB
   
   n*m is even (4*4)
   BWBW
   WBWB
   BWBW
   WBWB
    */

    if((n*m) % 2 == 1) {
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j < m; j++) {
          cout << (j % 2 == 0 ? 'W' : 'B');
        }
        cout << (i % 2 == 0 ? 'W' : 'B') << endl;
      }
    }
    else {
      for(int i = 1; i <= n; i++) {
        int fact = (i % 2 == 1);
        int j;
        for(j = 1; j < m; j++) {
          cout << (j % 2 == fact ? 'B' : 'W');
        }
        cout << (i >= n-1 ? 'B' : (j % 2 == !fact ? 'W' : 'B')) << endl;
      }
    }
  }

  return 0;
}