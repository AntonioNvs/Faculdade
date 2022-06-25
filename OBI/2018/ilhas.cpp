#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

#define MAXN 1010

using namespace std;

vector <pair<int, int>> graph[MAXN];

int main() {
  int N, M;

  cin >> N >> M;

  int v, u, w;
  for(int i = 0; i < M; i++) {
    cin >> v >> u >> w;

    graph[v].push_back(make_pair(u, w)); // distancia, peso
    graph[u].push_back(make_pair(v, w)); // distancia, peso
  }

  // As distâncias serão armazenadas negativas, já que por padrão
  // a priority_queue ordena pelo maior
  priority_queue<pair<int, int>> dj; // distancia, vertice
  
  int dist[N+1];
  for(int i = 1; i <= N; i++)
    dist[i] = INT32_MAX;

  int S;
  cin >> S;

  // Inicializo a distância do vértice atual como 0
  dist[S] = 0;

  dj.push(make_pair(0, S));

  while(!dj.empty()) {
    int v = dj.top().second;
    int cost = -dj.top().first;

    dj.pop();

    if(cost != dist[v]) continue;

    for(auto edge : graph[v]) {
      int u = edge.first;
      int w = edge.second;

      if(dist[u] > dist[v] + w) {
        dist[u] = dist[v] + w;
        dj.push(make_pair(-dist[u], u));
      }
    }
  }

  int maxi = -1, mini = INT32_MAX;
  for(int i = 1; i <= N; i++) {
    if(dist[i] == 0) continue;
    maxi = max(maxi, dist[i]);
    mini = min(mini, dist[i]);
  }

  cout << maxi-mini << endl;

  return 0;
}