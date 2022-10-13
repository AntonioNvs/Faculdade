#include <bits/stdc++.h>

using namespace std;

int contrary(int x) {
  if(x == 0) return 5;
  if(x == 1) return 3;
  if(x == 2) return 4;
  if(x == 3) return 1;
  if(x == 4) return 2;
  return 0;
}

int max_play(int sides[6], int down) {
  int maxi;
  if(down == 0 || down == 5)
    maxi = max(max(sides[1], sides[2]), max(sides[3], sides[4]));
  if(down == 1 || down == 3)
    maxi = max(max(sides[0], sides[5]), max(sides[2], sides[4]));
  else
    maxi = max(max(sides[0], sides[5]), max(sides[1], sides[3]));

  return maxi;
}

int main() {
  int N;
  cin >> N;

  pair<int, int> dices[N][6];
  int values[N][6];
  for(int i = 0 ; i < N; i++)
    for(int j = 0; j < 6; j++)
      cin >> values[i][j];

  for(int j = 0; j < 6; j++)
    dices[0][j] = make_pair(max_play(values[0], j), values[0][contrary(j)]);

  for(int i = 1; i < N; i++)
    for(int j = 0; j < 6; j++) {
      int c;
      for(int k = 0; k < 6; k++) {
        if(dices[i-1][k].second == values[i][j]) {
          c = k;
          break;
        }
      }
      dices[i][j] = make_pair(dices[i-1][c].first + max_play(values[i], j), values[i][contrary(j)]);
    }

  cout << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 6; j++)
      cout << dices[i][j].first << ' ';
    cout << endl;
  }
  return 0;
}