#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int t; cin >> t;

  while(t--) {
    ll N; cin >> N;
    string com; cin >> com;

    ll sum = 0LL;
    vector<ll> arr(N);
    for(ll i = 0; i < N; i++) {
      if(com[i] == 'L') arr[i] = i;
      else arr[i] = N-i-1;
      sum += arr[i];
    }

    vector<ll> up(N);
    for(ll i = 0; i < N; i++) {
      if(com[i] == 'L') up[i] = max(0LL, (N-i-1) - arr[i]);
      else up[i] = max(0LL, i - arr[i]);
    }

    sort(up.begin(), up.end());
    for(int i = N-1; i >= 0; i--) {
      sum += up[i];
      cout << sum << ' '; 
    }

    cout << endl;
  }

  return 0;
}