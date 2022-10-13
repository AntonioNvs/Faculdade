#include <bits/stdc++.h>

#define MAXN 200100
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int N, M;
int vis[MAXN];
vector<int> adj[MAXN];

/*
0 = not visited
1 = visiting
2 = already getted
*/
bool dfs(int x, int last) {
  if(vis[x] == 1)
    return true;

  if(vis[x] == 2)
    return false;

  vis[x] = 1;
  for(auto w : adj[x])
    if(w != last)
      if(dfs(w, x)) {
        vis[x] = 2;
        return adj[x].size() == 2;
      }

  vis[x] = 2;
  return false;

}

int main() { _
    cin >> N >> M;

    int a, b;
    for(int i = 0; i < M; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    int sum = 0;
    for(int i = 1; i <= N; i++)
      sum += dfs(i, -1);

    cout << sum << endl;
    return 0;
}