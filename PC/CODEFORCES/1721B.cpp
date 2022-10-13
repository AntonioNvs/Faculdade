#include <bits/stdc++.h>
#define MAXNM 1010
#define pp pair<pair<int, int>, int>

using namespace std;

int grid[MAXNM][MAXNM];

int main() {
  int T;
  cin >> T;
    
  int N, M, xi, yi, d;

  while(T--) {
    cin >> N >> M >> xi >> yi >> d;

    memset(grid, 0, sizeof(grid));
    
    for(int i = 1; i <= N; i++) 
      for(int j = 1; j <= M; j++) 
        if(abs(i - xi) + abs(j - yi) <= d)
          grid[i][j] = -1;

    queue<pp> dots;
    int ans = -1;
    dots.push(make_pair(make_pair(1, 1), 0));
    while(!dots.empty()) {
      pp dot = dots.front();
      dots.pop();
      int x = dot.first.first;
      int y = dot.first.second;
      int cost = dot.second;

      grid[x][y] = -1;

      if(x == N && y == M) {
        ans = cost;
        break;
      }

      if(x-1 >= 1 && grid[x-1][y] != -1) {
        dots.push({{x-1, y}, cost + 1});
      }

      if(x+1 <= N && grid[x+1][y] != -1) {
        dots.push({{x+1, y}, cost + 1});
      }

      if(y-1 >= 1 && grid[x][y-1] != -1) {
        dots.push({{x, y-1}, cost + 1});
      }

      if(y+1 <= M && grid[x][y+1] != -1) {
        dots.push({{x, y+1}, cost + 1});
      }
    }
    cout << ans << endl;
  }
  return 0;
}