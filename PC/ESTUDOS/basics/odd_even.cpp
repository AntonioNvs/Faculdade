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
    int a, b; cin >> a >> b;

    if(b == a) cout << '0' << endl;
    else if(b > a && (b-a) % 2 == 1) cout << '1' << endl;
    else if(a > b && (a-b) % 2 == 0) cout << '1' << endl;
    else cout << '2' << endl;

  }
  return 0;
}