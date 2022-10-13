#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int C;
  cin >> C;

  int maxi = 100, sum = 100, x;
  while(C--) {
    cin >> x;
    sum += x;
    maxi = max(maxi, sum);
  }

  cout << maxi << endl;
  
  return 0;
}