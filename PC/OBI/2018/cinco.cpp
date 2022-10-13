#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N;
  cin >> N;

  int v[N];
  int c = 0;
  for(int i = 0; i < N; i++) {
    cin >> v[i];
    if(v[i] % 5 == 0)
      c++;
  }

  if(c == 0) {
    cout << -1 << endl;
    return 0;
  }

  int idx = -1;
  for(int i = 0; i < N-1; i++) {
    if(v[i] % 5 == 0 && v[i] < v[N-1]) {
      idx = i;
      break;
    }
  }

  if(idx == -1)
    for(int i = N-2; i >= 0; i--)
      if(v[i] % 5 == 0) {
        idx = i; break;
      }

  int tmp = v[idx];
  v[idx] = v[N-1];
  v[N-1] = tmp;

  for(int i = 0; i < N; i++)
    cout << v[i] << ' ';
  cout << endl;
  return 0;
}