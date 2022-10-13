#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N, Q;
  cin >> N >> Q;

  int arr[N+1], prefix[N+1];
  cin >> arr[1];
  prefix[0] = 0;
  prefix[1] = arr[1];

  // Prefix sum
  for(int i = 2; i <= N; i++) {
    cin >> arr[i];
    prefix[i] = arr[i] + prefix[i-1];
  }

  int a, b;
  int ans = 0;
  while(Q--) {
    cin >> a >> b;
    ans += prefix[b] - prefix[a-1];
  }

  cout << ans << endl;
  
  return 0;
}