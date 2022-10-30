#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N; cin >> N;

  string word; 
  map<int, string> k;
  map<string, int> h;
  for(int i = N; i >= 1; i--) {
    cin >> word;
    k[i] = word;
  }

  for(auto p : k) {
    if(!h[p.second])
      cout << p.second << endl;
    h[p.second] = 1;
  }

  return 0;
}