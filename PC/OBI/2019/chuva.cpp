#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

#define MAX 510

using namespace std;

int N, M;
int visiteds[MAX][MAX];
char c[MAX][MAX];

int main() {
  memset(c, 'a', sizeof(c));
  memset(visiteds, 0, sizeof(visiteds));

  cin >> N >> M;

  int ii, ji;

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++) {
      cin >> c[i][j];
      if(c[i][j] == 'o') {
        ii = i;
        ji = j;
      }
    }

  queue<pair<int, int>> que;
  que.push(make_pair(ii, ji));
  
  while(!que.empty()) {
    pair<int, int> curr = que.front();
    que.pop();

    int i = curr.first;
    int j = curr.second;

    if(i < 1 || j < 1 || i > N || j > M || visiteds[i][j] == 1)
      continue;

    visiteds[i][j] = 1;

    if(c[i][j] == '.') {
      if(
        c[i-1][j] == 'o' ||
        (c[i][j-1] == 'o' && c[i+1][j-1] == '#') ||
        (c[i][j+1] == 'o' && c[i+1][j+1] == '#')
      ) {
        c[i][j] = 'o';
      }
    } else if(c[i][j] == '#') {
      continue;
    }

    que.push(make_pair(i-1, j));
    que.push(make_pair(i+1, j));
    que.push(make_pair(i, j-1));
    que.push(make_pair(i, j+1));
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cout << c[i][j];
    }

    cout << endl;
  }
    

  return 0;
}