#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(string w) {
  int size = w.length();
  for(int i = 0; i < size/2; i++) {
    if(w[i] != w[size-i-1])
      return false;
  }

  return true;
}

int found(string curr, int q) {
  if(is_palindrome(curr)) {
    return q + 1;
  } 
  
  int qtd = 9999999;

  qtd = min(qtd, found(curr.substr(0, curr.length()-1), q+1));

  return qtd;
}

int main() {
  int N;
  string word;

  cin >> N;
  cin >> word;

  int size = word.length()-1;
  string sub = word.substr(1, size);

  cout << sub << endl;

  return 0;
}