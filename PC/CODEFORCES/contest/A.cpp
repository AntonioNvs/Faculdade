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
    int N, M; cin >> N >> M;

    int x, y;
    int rows[10]; memset(rows, 0, sizeof(rows));
    int cols[10]; memset(cols, 0, sizeof(cols));

    for(int i = 0; i < M; i++) {
      cin >> x >> y;
      rows[x]++;
      cols[y]++;
    }
    bool right = true, cannot = false;
    int countR = 0, countC = 0;
    for(int i = 1; i <= N; i++) {
      right &= cols[i] && rows[i];
      if(cols[i] > 2 || rows[i] > 2) {
        cannot = true;
        break;
      }

      if(cols[i] == 2) countC++;
      if(rows[i] == 2) countR++;
    }

    if(M > N) cout << "NO" << endl;
    else if(N > M && (countC <= 1 && countR <= 1)) cout << "YES" << endl;
    else if(N == M && right) cout << "NO" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}