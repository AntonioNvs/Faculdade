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
  
  vector<double> paid(N, 0.0);
  vector<double> cons(N, 0.0);

  int k, i = 0;
  while(1) {
    cin >> k;

    if(k == -1) break;

    double sum = k;
    vector<double> parts(N+1);
    parts[0] = k;
    for(int j = 1; j < N; j++)
      cin >> parts[j], sum += parts[j];

    double v; cin >> v;

    for(int j = 0; j < N; j++) {
      if(i % N == j) paid[j] += v;
      cons[j] += v*parts[j]/sum;
    }
    i++;
  }

  cout << setprecision(2) << fixed;

  for(int j = 1; j <= N; j++) {
    double diff = paid[j-1] - cons[j-1];

    if(diff >= 0)
      cout << "irmao " << j << " recebe " << diff << endl;
    else
      cout << "irmao " << j << " deve " << fabs(diff) << endl;
  }
  return 0;
}