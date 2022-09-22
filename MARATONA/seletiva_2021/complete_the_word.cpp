#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;

  cin >> s;

  int exists = -1;

  for(int i = 0; i <= s.size()-26; i++) {
    string t = s.substr(i, 26);
    set<char>h;
    int visits[26]={};
    int q = 0;

    for(int j = 0; j < 26; j++) {
      if(t[j] == '?') q++;
      else h.insert(t[j]), visits[(int)(t[j]-'A')] = 1;
    }

    if(h.size() + q == 26){
      exists = i;
      for(int j = i; j < i + 26; j++) {
        if(s[j] == '?') {
          for(int k = 0; k < 26; k++) {
            if(visits[k] == 0) {
              s[j] = (char)('A' + k), visits[k] = 1;
              break;
            }
          }
        }
      }
      break;
    }
  }

  if(exists == -1)
    cout << -1 << endl;
  else {
    for(int i = 0; i < s.size(); i++)
      if(s[i] == '?')
        s[i] = 'A';
    cout << s << endl; 
  }
  return 0;
}