#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int i, n; cin >> n;

  map<int, int> h;
  while(n--) {
    cin >> i;
    h[i]++;
  }

  for(auto x : h)
    h[x.first] /= 2;

  int sum = 0;
  for(auto x : h)
    sum += x.second;

  cout << sum/2 << endl;

  return 0;
}