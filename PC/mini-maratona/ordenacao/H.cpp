#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int j(int n, int k) {
  if(n == 1) return 1;
  return (j(n-1, k) + k - 1) % n + 1;
}

int main() { _
  int A, P;

  while(cin >> A >> P) {
    cout << j(A, P) << endl;
  }
  return 0;
}