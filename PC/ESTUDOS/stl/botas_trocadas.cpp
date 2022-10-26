#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N; cin >> N;

  int num; char p;
  int arr[65][2];

  memset(arr, 0, sizeof(arr));

  while(N--) {
    cin >> num >> p;
    if(p == 'D') arr[num][0]++;
    else arr[num][1]++;
  }

  int ans = 0;
  for(int i = 30; i <= 60; i++)
    ans += min(arr[i][0], arr[i][1]);

  cout << ans << endl;

  return 0;
}