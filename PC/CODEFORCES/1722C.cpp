#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;

    string his[3][N];
    map<string, int> h;

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < N; j++) {
        string word;
        cin >> word;

        his[i][j] = word;
        h[word]++;
      }
    }

    int p[3] = {0, 0, 0};
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < N; j++) {
        string word = his[i][j];
        if(h[word] == 1)   
          p[i] += 3;
        else if(h[word] == 2)
          p[i] += 1;
      }
    }

    cout << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
  }
  return 0;
}