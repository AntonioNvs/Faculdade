#include <iostream>

using namespace std;

int main() {
  int N, options[5][5];
  cin >> N;

  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      options[i][j] = 0;

  options[0][1] = 1;
  options[0][2] = 1;
  options[1][2] = 1;
  options[1][3] = 1;
  options[2][3] = 1;
  options[2][4] = 1;
  options[3][4] = 1;
  options[3][0] = 1;
  options[4][0] = 1;
  options[4][1] = 1;

  int pnt = 0;

  for(int i = 0; i < N; i++) {
    int x, d;
    cin >> x >> d;

    if(options[x][d] == 1) pnt++;
    if(options[d][x] == 1) pnt--;
  }

  if(pnt > 0)
    cout << "dario" << endl;
  else
    cout << "xerxes" << endl;

  return 0;
}