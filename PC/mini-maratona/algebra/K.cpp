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
  int a, b; cin >> a >> b;

  int r = __gcd(a, b);

  if(r == 1)
    cout << "Fica na colmeia" << endl;
  else {
    cout << a/r << ' ' << b/r << ' ' << r << endl;
  }
  return 0;
}