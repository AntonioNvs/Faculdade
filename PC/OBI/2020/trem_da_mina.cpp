#include <bits/stdc++.h>

#define MAXE 10010
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pipii pair<int, pair<int, int>>
using namespace std;

int E, R;
vector<pii> adj[MAXE];

int dijsktra(int x, int tam) {
  int dists[MAXE];
  int visiteds[MAXE];

  for(int i = 1; i <= E; i++) {
    dists[i] = INF;
    visiteds[i] = 0;
  }

  priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
  pq.push({0, {-1, x}});
  dists[x] = 0;

  while(!pq.empty()) {
    pipii p = pq.top();
    pq.pop();

    int cost = p.first;
    int last = p.second.first;
    int u = p.second.second;

    if(visiteds[u] != 0)
      continue;

    if(u != x)
      visiteds[u] = 1;

    if(u == x && cost != 0)
      break;
    cout << u << endl;

    for(auto w : adj[u]) {
      if(w.second == last)
        continue;

      int dist = cost + w.first;
      int v = w.second;
      if(dist < dists[v] || dists[v] == 0) {
        dists[v] = dist;
        pq.push({dist, {u, v}});
      }
    }
  }

  if(dists[x] == 0)
    return -1;
  return dists[x];
}

int main() {
  cin >> E >> R;

  int a, b, c;

  for(int i = 0; i < R; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  int K, x, t;
  cin >> K;

  for(int i = 0; i < K; i++) {
    cin >> x >> t;
    cout << dijsktra(x, t) << endl;
  }

  return 0;
}