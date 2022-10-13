#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int N, C, P, I, tmp;

  cin >> N >> C;

  int info[N+1];

  memset(info, 0, sizeof(info));

  for(int j = 0; j < C; j++) {
    cin >> P >> I;

    for(int k = 0; k < I; k++) {
      cin >> tmp;
      info[tmp] = P;
    }
  }

  for(int i = 1; i <= N; i++)
    if(info[i] == 0)
      cout << i << endl;
      
  return 0;
}