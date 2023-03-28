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
  int N; cin >> N;

  double k = sqrt(N);

  if((int)k == k) {
    cout << "Quadrado perfeito" << endl;
    cout << N << endl;
    cout << k << endl;
  } else {
    cout << "Nao eh quadrado perfeito" << endl;
    cout << (int)floor(k)*floor(k) << endl;
    cout << (int)floor(k) << endl;
  }

  return 0;
}