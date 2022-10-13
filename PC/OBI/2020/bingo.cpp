#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int N, K, U;

  cin >> N >> K >> U;

  int cartels[N+1][U+1];
  memset(cartels, 0, sizeof(cartels));

  int num;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < K; j++) {
      cin >> num;
      cartels[i][num]++;
    }
    cartels[i][0] = K;
  }

  // Rodando o sorteio
  bool found = false;
  for(int i = 0; i < U; i++) {
    cin >> num;

    for(int j = 0; j < N; j++) {
      if(cartels[j][num] == 1)
        cartels[j][0]--;

      if(cartels[j][0] == 0) {
        cout << j+1 << " "; 
        found = true;
      }
    }

    if(found)
      break;
  }

  return 0;
}