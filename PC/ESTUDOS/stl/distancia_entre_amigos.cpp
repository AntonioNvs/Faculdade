#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N; cin >> N;
  int mini = -INF;

  int h, ans = -1;
  for(int i = 0; i < N; i++) {
    cin >> h;

    mini++;

    ans = max(ans, h + mini);
    mini = max(mini, h);
  }

  cout << ans << endl;

  return 0;
}