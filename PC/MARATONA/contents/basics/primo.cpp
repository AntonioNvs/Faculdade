#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

bool prime(ll N) {
  for(ll i = 2LL; i*i <= N; i++)
    if(N % i == 0)
      return false;
  return true;
}

int main() { _  
  ll N; cin >> N;

  cout << (prime(N) ? "sim" : "nao") << endl;

  return 0;
}