#include <iostream>

#define MAXLC 110
#define WALL '/'

using namespace std;

int L, C;
int ii, ji, ie, je;

char grid[MAXLC][MAXLC];
int visiteds[MAXLC][MAXLC];

int dL[] = {1, -1, 0, 0};
int dC[] = {0, 0, 1, -1};

bool limits(int l, int c) {
  return l >= 1 && c >= 1 && l <= L && c <= C && visiteds[l][c] == 0;
}

void backtracking(int l, int c) {
  visiteds[l][c] = 1;
  int qtd = 0;

  for(int i = 0; i < 4; i++) {
    int nl = l + dL[i];
    int nc = c + dC[i];

    if(limits(nl, nc))
      if(grid[nl][nc] == 'H') {
        qtd++;
        backtracking(nl, nc);
      }
  }
  
  if(qtd == 0) {
    ie = l;
    je = c;
  }

  visiteds[l][c] = 0;
}

int main() {
  for(int i = 0; i < MAXLC; i++)
    for(int j = 0; j < MAXLC; j++) {
      grid[i][j] = WALL;
      visiteds[i][j] = 0;
    }

  cin >> L >> C;

  for(int i = 1; i <= L; i++)
    for(int j = 1; j <= C; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'o') {
        ii = i;
        ji = j;
      }
    }

  backtracking(ii, ji);

  cout << ie << ' ' << je << endl;
}