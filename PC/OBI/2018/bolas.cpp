#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  map<int, int> memo;

  int t;
  for(int i = 0; i < 8; i++) {
    cin >> t;
    memo[t]++;
  }

  for(auto x : memo) {
    if(x.second > 4) {
      cout << 'N' << endl;
      return 0;
    }
  }

  cout << 'S' << endl;

  return 0;
}