#include <bits/stdc++.h>

#define MAXN 210
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define FULL -1
#define EMPTY 0
#define COLOR 1

typedef const long long ll;

using namespace std;

int N, M;
int grid[MAXN][MAXN];

int mx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int my[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int dfs(int x, int y) {
    if(x <= 0 or x > N or y <= 0 or y > M) return 0;
    if(abs(grid[x][y])) return 0;

    grid[x][y] = COLOR;
    int sum = 1;
    for(int i = 0; i < 8; i++)
        sum += dfs(x + mx[i], y + my[i]);

    return sum;
}

int main() {
    _

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            grid[i][j] = EMPTY;
    
    int x, y, k, a, b;

    cin >> N >> M >> x >> y >> k;

    while(k--) {
        cin >> a >> b;
        grid[a][b] = FULL;
    }

    cout << dfs(x, y) << endl;
}