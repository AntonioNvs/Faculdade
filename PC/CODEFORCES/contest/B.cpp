#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

#define pii pair<ll, ll>

bool compare(pair<ll, pii> a, pair<ll, pii> b) {
  return a.second.second < b.second.second;
}

int main() { _
  int t; cin >> t;

  while(t--) {
    ll N; cin >> N;  
    vector<pair<ll, pii>> arr(N);

    vector<pii> neigh(N); 

    ll a, b;
    for(ll i = 0; i < N; i++) {
      neigh[i].first = i-1;
      neigh[i].second = i+1;
      arr[i].first = i;
      cin >> arr[i].second.first;
    }

    for(ll i = 0; i < N; i++)
      cin >> arr[i].second.second;

    sort(arr.begin(), arr.end(), compare);
    
    ll ans = 0LL;
    for(ll i = 0; i < N; i++) {
      ll idx = arr[i].first;
      ll left = neigh[i].first;
      ll right = neigh[i].second;

      ans += arr[i].second.first;

      if(left >= 0 && left < N) ans += arr[i].second.second, neigh[left].second = right;
      if(right >= 0 && right < N) ans += arr[i].second.second, neigh[right].first = left;
    }

    cout << ans << endl;
  }
  return 0;
}