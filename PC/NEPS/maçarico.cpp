#include <bits/stdc++.h>
#define MAXN 110
#define pb push_back

using namespace std;

vector<int> adj[MAXN];
bool visiteds[MAXN];
int n_graph[MAXN];

int dfs(int x) {
    visiteds[x] = true;

    int dist = 1;
    for(auto v : adj[x])
        if(!visiteds[v])
            dist = max(dist, 1 + dfs(v));
    
    return dist;
}

void convex(int x, int color) {
    n_graph[x] = color;

    for(auto v : adj[x])
        if(n_graph[v] == 0)
            convex(v, color); 
}

int main() {
    int N, M; cin >> N >> M;

    while(M--) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    for(int i = 1; i <= N; i++) n_graph[i] = 0;

    int c = 1;
    for(int i = 1; i <= N; i++) {
        if(n_graph[i] > 0) continue;
        convex(i, c), c++;
    }

    int maxis[c];
    for(int i = 1; i < c; i++) maxis[i] = 0;

    for(int v = 1; v <= N; v++) {
        for(int i = 0; i <= N; i++) visiteds[i] = false;

        maxis[n_graph[v]] = max(maxis[n_graph[v]], dfs(v));
    }

    int ans = 0;
    for(int i = 1; i < c; i++)
        ans += (int)maxis[i]/2;

    cout << ans << endl;

    return 0;
}