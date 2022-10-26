#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

ll sum(int x) {
  return x*(x-1)/2;
}

int main() { _
  int N;
  cin >> N;

  int arr[N+1];

  for(int i = 1; i <= N; i++) cin >> arr[i];

  int i = 1, c;
  ll ans = (ll)N;

  while(i <= N) {
    int k = arr[i];
    int init = i;
    i++;
    c = 0;

    while(i <= N && arr[i] == k) 
      c++, i++;

    ans += sum(c+1);
  }

  cout << ans << endl;
}