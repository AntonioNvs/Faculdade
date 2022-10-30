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
    int N; cin >> N;

    vector<int> pot(N+1);
    int sum = 0;
    for(int i = 1; i <= N; i++)
      pot[i] = pow(2, i), sum += pot[i];

    int a = pot[N], b = 0, k = 1;
    while(k < N/2) {
      a += pot[k];
      k++;
    }

    cout << abs(2*a - sum) << endl;
  }
  return 0;
}