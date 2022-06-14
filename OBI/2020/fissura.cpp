#include <iostream>
#include <cstring>

#define MAXN 510
#define VAL -1 

using namespace std;

int levels[MAXN][MAXN];
int visiteds[MAXN][MAXN];
int N, F;

void dfs(int i, int j) {
  if(visiteds[i][j] == 1 or i < 0 or j < 0 or i == N or j == N)
    return;

   visiteds[i][j] = 1;

  if(levels[i][j] > F)
    return;
  else
    levels[i][j] = VAL;

  dfs(i+1, j);
  dfs(i-1, j);
  dfs(i, j+1);
  dfs(i, j-1);
}

int main() {
  cin >> N >> F;

  memset(visiteds, 0, sizeof(visiteds));

  string row;

  for(int i = 0; i < N; i ++) {
    cin >> row;
    for(int j = 0; j < N; j++) {
      levels[i][j] = row[j] - '0';
    }
  }

  dfs(0, 0);

  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j++)
      if(levels[i][j] == VAL)
        cout << "*";
      else
        cout << levels[i][j];
    
    cout << endl;
  }

  return 0;
}