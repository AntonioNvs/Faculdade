#include <bits/stdc++.h>

using namespace std;

int main() {
  string sentence;

  cin >> sentence;
  
  int ans = sentence.size(), length = sentence.size();
  for(int l = 0; l < 26; l++) {
    int last_occ = -1, max_occ = 0;
    for(int i = 0; i < length; i++) {
      if(sentence[i] == l + 'a') {
        max_occ = max(max_occ, i - last_occ);
        last_occ = i;
      }
    }
    max_occ = max(max_occ, length - last_occ);
    ans = min(ans, max_occ);
  }

  cout << ans << endl;
  return 0;
}