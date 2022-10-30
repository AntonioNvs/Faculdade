#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;
#define pii pair<ll, ll>

int sig(int n) {
  if(n > 0) return 1;
  else return -1;
}

int main() { _
  int t; cin >> t;

  while(t--) {
    int N; cin >> N;

    vector<int> arr(N);
    for(auto &u : arr) cin >> u;

    pii sum = {0, 0};
    int crr = 0;
    while(crr < N) {
      int signal (!sum.first ? sig(arr[crr]) : sum.first);
      
      int greater = arr[crr++];
      while(crr < N && sig(arr[crr]) == signal) greater = max(arr[crr], greater), crr++;

      sum.second += (ll)greater;
      sum.first = (signal == 1 ? -1 : 1);
    }
    cout << sum.second << endl;
  }
  return 0;
}