#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N, K;
  cin >> N >> K;

  int x;
  map<int, int> h;
  for(int i = 0; i < N; i++){
    cin >> x;
    h[x]++;
  }

  int count = 1;
  int ans = 0;

  for(auto p : h) {
    ans += p.second*count;
    count++;
  }

  if(ans > K)
    cout << "nao" << endl;
  else {
    vector<int>prizes;

    cout << endl;
  }

  return 0;
}