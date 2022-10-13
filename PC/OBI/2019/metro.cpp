#include <bits/stdc++.h>

#define MAXN 100100
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int dist[2][MAXN];
int pai[2][MAXN];

int N, M;

vector<int> adj[2][MAXN];

// Achar a distância do rolê
void dfs(int u, int p, int q) {
  for(auto w : adj[q][u]) {
    if (w == p) continue;
    dist[q][w] = dist[q][u] + 1;
    pai[q][w] = u;
    dfs(w, u, q);
  }

}

int find_center(int q) {
  dist[q][1] = 0;
  dfs(1, 0, q);

  int maxi = -1, u;
  for(int i = 1; i <= (q == 0 ? N : M); i++)
    if(dist[q][i] > maxi)
      maxi = dist[q][i], u = i;

  dist[q][u] = 0;
  dfs(u, 0, q);
  
  maxi = -1;
  int v;
  for(int i = 1; i <= (q == 0 ? N : M); i++)
    if(dist[q][i] > maxi)
      maxi = dist[q][i], v = i;

  int crr = v, qtd = 0;

  while(true) {
    if(qtd == dist[q][v]/2) return crr;
    crr = pai[q][crr];
    qtd++;
  }
}

int main() { _
  cin >> N >> M;

  int a, b;
  for(int i = 1; i < N; i++) {
    cin >> a >> b;
    adj[0][a].push_back(b);
    adj[0][b].push_back(a);
  }

  for(int i = 1; i < M; i++) {
    cin >> a >> b;
    adj[1][a].push_back(b);
    adj[1][b].push_back(a);
  }

  cout << find_center(0) << ' ' << find_center(1) << endl;

  return 0;
}