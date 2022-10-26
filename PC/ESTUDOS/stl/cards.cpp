#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int n; cin >> n;
  string w; cin >> w;

  map<char, int> h;

  for(int i = 0; i < n; i++) h[w[i]]++;

  int mini = -1;

  while(h['n'] > 0 && h['e'] > 0 && h['o'] > 0) {
    cout << '1' << ' ';
    h['o']--, h['n']--, h['e']--;
  }

  
  while(h['z'] > 0 && h['e'] > 0 && h['r'] > 0 && h['o'] > 0) {
    cout << '0' << ' ';
    h['z']--, h['e']--, h['r']--, h['o']--;
  }
  
  return 0;
}