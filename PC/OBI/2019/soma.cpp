#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int N, K;

  cin >> N >> K;

  int sequence[N+1];
  int prefix[N+1];

  memset(prefix, 0, sizeof(prefix));

  for(int i = 1; i <= N; i++) {
    cin >> sequence[i];
    prefix[i] = sequence[i] + prefix[i-1];
  }

  int qtd = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j++) {
      if(prefix[j] - prefix[i-1] == K)
        qtd++;
      if(prefix[j] - prefix[i-1] > K)
        break;
    }
  }
  
  cout << qtd << endl;

  return 0;
}