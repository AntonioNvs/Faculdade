#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  int N;

  cin >> N;

  char foot;
  int size;

  int shoots[65][2];

  memset(shoots, 0, sizeof(shoots));

  for(int i = 0; i < N; i++) {
    cin >> size >> foot;
    shoots[size][foot - 'D']++;
  }

  int qtd = 0;
  for(int i = 30; i <= 60; i++)
    qtd += min(shoots[i][0], shoots[i][1]);

  cout << qtd << endl;

  return 0;
}