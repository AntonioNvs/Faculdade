#include <iostream>
#include <queue>
#include <utility>

#define oo 1000000000
#define MAXN 110
#define pii pair<int, int>

using namespace std;

int N, M;
vector<pii> adj[MAXN];
int dists[MAXN];
int visiteds[MAXN];

void dj() {
  priority_queue<pii, vector<pii>, greater<pii>> queue;
  dists[1] = 0;

  queue.push(make_pair(dists[1], 1));

  while(!queue.empty()) {
    pii crr = queue.top();
    queue.pop();

    if(visiteds[crr.second] == 1)
      continue;

    int dist = crr.first;
    int u = crr.second;

    visiteds[u] = 1;

    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      int cost = adj[u][i].second;

      if(dist + cost < dists[v]) {
        dists[v] = dist + cost;
        queue.push(make_pair(dists[v], v));
      }
    }
  } 
}

int main() {
  int a, b, cost;
  cin >> N >> M;

  for(int i = 0; i < M; i++) {
    cin >> a >> b >> cost;
    adj[a].push_back(make_pair(b, cost));
    adj[b].push_back(make_pair(a, cost));
  }

  for(int i = 0; i < MAXN; i++) {
    dists[i] = oo;
    visiteds[i] = 0;
  }

  dj();

  cout << dists[N] << endl;
}