#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

bool compare(pii a, pii b) {
  return a.first < b.first;
}

int main() { _
  int N, K;
  cin >> N >> K;

  int colors[N+1];
  vector<pii> blocks(N);

  for(int i = 0; i < N; i++) {
    cin >> blocks[i].first >> blocks[i].second;
    colors[i] = blocks[i].second;
  }

  sort(blocks.begin(), blocks.end(), compare);

  bool ok = true;
  for(int i = 0; i < blocks.size(); i++) {
    if(colors[i] != blocks[i].second) {
      ok = false;
      break;
    }
  }

  if(ok) cout << 'Y' << endl;
  else cout << 'N' << endl;

  return 0;
}