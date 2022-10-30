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
  vector<int> kardano(N);
  for(auto &u : arr) cin >> u;

  kardano[0] = arr[0];

  int maxi = -INF;
  for(int i = 1; i < N; i++) {
    kardano[i] = max(arr[i], arr[i] + kardano[i-1]);
    maxi = max(kardano[i], maxi);
  }

  cout << maxi << endl;

  return 0;
}