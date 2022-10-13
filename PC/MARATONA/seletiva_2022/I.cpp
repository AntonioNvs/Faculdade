#include <bits/stdc++.h>

using namespace std;

int main() {
  string word;
  cin >> word;

  int characters[26];
  memset(characters, 0, sizeof(characters));

  int last_occ = -1;
  for(int i = 25; i >= 0; i--) {
    for(int j = last_occ+1; j < word.size(); j++) {
      if(word[j] == (char)i + 'a') {
        last_occ = j;
        characters[i]++;
      }
    }
  }

  for(int i = 25; i >= 0; i--) {
    for(int j = 0; j < characters[i]; j++)
      cout << (char)(i+'a');
  }

  cout << endl;
  return 0;
}