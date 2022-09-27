#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, N, colors[20];
  cin >> T;

  while(T--) {
    int maxi = -1;
    cin >> N;
  
    for(int i =0; i < N; i++) {
      cin >> colors[i];
      maxi = max(maxi, colors[i]);
    };

    for(int i =0; i < N; i++) {
      if(colors[i] == maxi) {
        cout << i + 1 << endl;
        break;
      }
    }
  }

  return 0;
}