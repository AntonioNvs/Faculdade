#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int qtd[26];
  int sum = 0;
  int P;

  memset(qtd, 0, sizeof(qtd));
  string match, curinga;

  cin >> match >> curinga;

  P = match.length();

  for(int i = 0; i < P; i++) {
    if(curinga[i] != '*') {
      int c = curinga[i] - 'a';
      qtd[c]++;
      sum++;
    }
  }

  for(int i = 0; i < P; i++) {
    int c = match[i] - 'a';
    if(qtd[c] > 0) {
      sum--;
      qtd[c]--;
    }
  }

  if(sum == 0)
    cout << "S" << endl;
  else
    cout << "N" << endl;

  return 0;
}