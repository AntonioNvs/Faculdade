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

bool prime(int N) {
  for(int i = 2; i*i <= N; i++)
    if(N % i == 0)
      return false;
  return true;
}

int main() { _
  int N, M;
  while(cin >> N >> M) {
    int qtd = 0;
    if(N < M) {
      for(int i = N+1; i < M; i++)
        if(prime(i))
          cout << i << ' ', qtd++;
    }
    else
      for(int i = N-1; i > M; i--)
        if(prime(i))
          cout << i << ' ', qtd++;

    if(!qtd) cout << 0 << endl;
    else cout << endl;
  }
  return 0;
}