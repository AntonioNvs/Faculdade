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
  int C, M; cin >> C >> M;

  int sum = 0, t;
  for(int i = 0; i < M; i++) {
    cin >> t;
    sum += t;
  }

  cout << C*sum << endl;

  return 0;
}