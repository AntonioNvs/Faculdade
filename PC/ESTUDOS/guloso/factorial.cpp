#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

vector<int> memo(11, -1);

int fact(int n) {
  if(n <= 1) return memo[n] = 1;
  if(memo[n] != -1) return memo[n];
  return memo[n] = n * fact(n-1);
}

int main() { _
  fact(10);

  int N; cin >> N;
  
  int k = 0;
  while(N) {
    int idx = (lower_bound(memo.begin(), memo.end(), N) - memo.begin());
    if(binary_search(memo.begin(), memo.end(), N))
      N -= memo[idx];
    else
      N -= memo[idx-1];
    k++;
  }

  cout << k << endl;

  return 0;
}