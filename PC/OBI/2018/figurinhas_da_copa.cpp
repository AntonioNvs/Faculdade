#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int N, C, M;

  cin >> N >> C >> M;

  int carimb[N+1];

  int num;

  memset(carimb, 0, sizeof(carimb));

  for(int i = 1; i <= C; i++) {
    cin >> num;
    carimb[num]++;
  }

  for(int i = 1; i <= M; i++) {
    cin >> num;
    
    if(carimb[num]) {
      carimb[num]--;
      C--;
    }
  }

  cout << C << endl;

  return 0;
}