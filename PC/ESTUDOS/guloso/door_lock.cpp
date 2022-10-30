#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int sig(int n) {
  if(n > 0) return 1;
  return -1;
}

int main() { _
  int N, M; cin >> N >> M;

  vector<int> pins(N);
  for(auto &u : pins) cin >> u;

  int crr = 0, sum = 0;
  while(crr < N-1) {
    if(pins[crr] == M) {
      crr++; continue;
    }

    int add = M-pins[crr];
    pins[crr] += add;
    pins[crr+1] += add;
    sum += abs(add);
    
    crr++;  
  }

  sum += abs(M-pins[N-1]);

  cout << sum << endl;

  return 0;
}