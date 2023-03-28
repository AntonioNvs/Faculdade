#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long int ll;

int main() { _
  int t; cin >> t;

  int n, k;
  while(t--) {
    cin >> n >> k;
    int p = n-1;
    int l = (ceil(k/p)-1)*n;
    cout << l << endl;
  }
  return 0;
}