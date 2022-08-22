#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 12

using namespace std;

int grid[MAXN][MAXN];
int N, M, xe, ye, xs, ys;

int cost = 0, resp = -1;

int movL[] = {0, 0, -1, 1};
int movC[] = {1, -1, 0, 0};

void dfs(int i, int j) {
  grid[i][j] = 1;
  cost++;

  if(i == xs && j == ys)
    resp = max(resp, cost);
  else
    for(int k = 0; k < 4; k++) {
      int l = i + movL[k];
      int c = j + movC[k];
      
      if(l >= 1 && c >= 1 && l <= N && c <= M && grid[l][c] == 0)
        dfs(l, c);
    }
  
  grid[i][j] = 0;
  cost--;
}

int main() {
  cin >> N >> M;
  cin >> xe >> ye >> xs >> ys;

  memset(grid, 0, sizeof(grid));

  for(int i = 2; i <= N; i+=2)
    for(int j = 2; j <= M; j+=2)
      grid[i][j] = 1;

  dfs(xe, ye);

  cout << resp << endl;

  return 0;
}