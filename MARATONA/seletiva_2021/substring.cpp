#include <bits/stdc++.h>
#define MAX 300100

using namespace std;

int N, M;

bool visiteds[MAX];
char nodes[MAX];
map<char, int> hashh;
vector<int> adj[MAX];

void dfs(int v) {
  if(visiteds[v])
    return;
  
  hashh[nodes[v]]++;
  visiteds[v] = true;

  for(int i = 0; i < adj[v].size(); i++)
    dfs(adj[v][i]);
}

int main() {
  int u, v;
  string path;
  cin >> N >> M >> path;

  for(int i = 1; i <= N; i++) {
    nodes[i] = path[i];
    visiteds[i] = false;
  }
  
  for(int i = 1; i <= M; i++) {
    cin >> u >> v;

    adj[u].push_back(v);
  }

  for(int i = 1; i <= N; i++)
    dfs(i);

  int maxi = -1;
  for(auto x: hashh)
    maxi = max(maxi, x.second);

  cout << maxi << endl;

  return 0;
}