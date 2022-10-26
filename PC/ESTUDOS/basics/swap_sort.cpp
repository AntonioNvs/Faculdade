#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N; cin >> N;
  vector<int> arr(N);
  for(auto &u : arr) cin >> u;

  vector<pii> swaps;

  for(int i = 0; i < N; i++) {
    int mini = arr[i];
    int idx = i;
    
    for(int j = i+1; j < N; j++)
      if(arr[j] < mini) {
        mini = arr[j];
        idx = j;
      }

    if(idx != i) {
      swap(arr[i], arr[idx]);
      swaps.push_back({i, idx});
    }
  }

  cout << swaps.size() << endl;
  for(auto x : swaps)
    cout << x.first << ' ' << x.second << endl;
    
  return 0;
}