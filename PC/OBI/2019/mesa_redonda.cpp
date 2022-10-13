#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int a, b, c, c1, c2, c3;
  cin >> a >> b;

  c1 = a % 3;
  c2 = a % 3;
  if(c1 == c2)
    c2 = (a+1) % 3;

  if(c1 == 1 && c2 == 0)
    cout << 2 << endl;
  if(c1 == 1 && c2 == 2)
    cout << 0 << endl;
  if(c1 == 2 && c2 == 0)
    cout << 1 << endl;
  if(c1 == 2 && c2 == 1)
    cout << 0 << endl;
  if(c1 == 0 && c2 == 1)
    cout << 2 << endl;
  if(c1 == 0 && c2 == 2)
    cout << 1 << endl;
  return 0;
}