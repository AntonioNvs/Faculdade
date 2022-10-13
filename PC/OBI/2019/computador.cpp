#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>

using namespace std;
typedef long long int ll;

int main() {
  int N, M;
  cin >> N >> M;

  int code, i, V;
  // {less_index, upper_index} , {code, V}
  vector<pair<pii, pii>> inst;

  while(M--) {
    cin >> code;

    if(code == 1 || code == 2)
      cin >> i >> V;
    else
      cin >> i;

    if(code == 1)
      inst.push_back({{i, min(N, V+i-1)}, {code, V}});
    else if(code == 2)
      inst.push_back({{max(0, i-V+1), i}, {code, V}});
    else {
      ll sum = 0;
      for(auto x : inst) {
        if(i >= x.first.first && i <= x.first.second) {
          if(x.second.first == 1)
            sum += x.second.second - i + x.first.first;
          else
            sum += x.second.second + i - x.first.second;
        }
      }

      cout << sum << endl;
    }
  }
  return 0;
}
/*
  1 4 3
  0 0 0 3 2 1

  2 4 3
  0 1 2 3
*/