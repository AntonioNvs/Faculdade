#include <bits/stdc++.h>

#define MAXN 50100

using namespace std;

int N;
int visiteds[MAXN];
vector<int> adj[MAXN];
int maxi = -1;
int c = 0;

void dfs(int x, int dist) {
  if(visiteds[x] != -1)
    return;

  visiteds[x] = 1;

  if(dist > maxi) {
    maxi = dist;
    c = 1;
  } else if(dist == maxi)
    c++;
  
  for(int y : adj[x])
    dfs(y, dist + 1);
}

int main() {
  cin >> N;
  int w, u;
  
  for(int i = 1; i < N; i++) {
    cin >> w >> u;
    adj[w].push_back(u);
    adj[u].push_back(w);
  }

  for(int i = 1; i <= N; i++) {
    memset(visiteds, -1, sizeof(visiteds));
    dfs(i, 1);
  }

  cout << maxi << endl;
  cout << c << endl;

  return 0;
}