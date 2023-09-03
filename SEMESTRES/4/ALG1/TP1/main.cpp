#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 100100
#define MAXM 100100
#define pb push_back
#define f first
#define s second

using namespace std;

struct Point {
    double x;
    double y;
};

int N, M;

pair<int, int> crr_exec;

vector<int> history(MAXN, 0);
vector<int> reverse_history(MAXN, 0);

Point points[MAXN];

vector<int> adj[MAXN];
vector<vector<int>> faces;

double relative_inclination(Point p, Point q) {
    return atan2(q.y - p.y, q.x - p.x);
}

double distance(Point a, Point b) {
    double x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x*x + y*y);
}

int curve_type(Point a, Point b, Point c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // left.
    if (v > 0) return +1; // right.
    return 0; // forward.
}

bool compare(int a, int b) {
    Point v = points[crr_exec.f];
    Point father = points[crr_exec.s];

    if(curve_type(father, v, points[a]) < curve_type(father, v, points[b]))
        return true;
    else
        return distance(points[a], v) < distance(points[b], v);
}

void dfs(int v, int father, int counter) {
    history[counter] = v;
    reverse_history[v] = counter;

    // Caso seja a primeira execução, escolha os vértices normalmente
    if(father == -1) {
        for(auto u : adj[v]) {
            if(u == father) continue;

            dfs(u, v, counter + 1);
        }
        return;
    }

    crr_exec = {v, father};

    sort(adj[v].begin(), adj[v].end(), compare);

    cout << v << ": ";

    for(auto u : adj[v]) {
        if(u == father) continue;
        cout << u << " ";

        if(reverse_history[u] != 0) {
            vector<int> face(history.begin() + reverse_history[u], history.begin() + counter);
            faces.pb(face);
            
        } else 
            dfs(u, v, counter + 1);

    }
    cout << endl;

    history[counter] = 0;
    reverse_history[v] = 0;
}

int main() {
    cin >> N >> M;

    double x, y;
    int d, v;

    int left = -1;
    for(int i = 1; i <= N; i++) {
        cin >> x >> y >> d;
        points[i] = {x, y};
        
        if(left == -1)
            left = i;
        else if(x < points[left].x || (x == points[left].y && y < points[left].y))
            left = i;

        while(d--) {
            cin >> v;
            adj[i].pb(v);
        }
    }

    // Chamar a dfs no vértice o mais a esquerda possível
    dfs(left, -1, 1);

    cout << faces.size() << endl;
}