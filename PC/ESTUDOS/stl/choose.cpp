#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N, M; 
  
  vector<int> belogs(210, 0);

  cin >> N;
  vector<int> A(N);
  for(auto &u : A) {
    cin >> u;
    belogs[u] = 1;
  }

  cin >> M;
  vector<int> B(M);
  for(auto &u : B) {
    cin >> u;
    belogs[u] = 1;
  }

  for(auto x : A)
    for(auto y : B)
      if(!belogs[x + y]) {
        cout << x << ' ' << y << endl;
        return 0;
      }
  return 0;
}