#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    cout << floor((N-2)/3)-1 << endl;
  }
}