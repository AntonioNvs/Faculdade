#include <bits/stdc++.h>

using namespace std;

int main() {
  string N;
  cin >> N;
  int M;
  cin >> M;

  string word;

  int ans = 0;
  for(int i = 0; i < M; i++) {
    cin >> word;
    if(word.size() != N.size())
      continue;

    char h[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};

    bool can = true;

    for(int j = 0; j < N.size(); j++) {
      int idx = word[j]-'a';
      if(h[idx] != N[j]) {
        can = false;
        break;
      }
    }

    if(can) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
