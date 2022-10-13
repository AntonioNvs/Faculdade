#include <iostream>

using namespace std;

bool z_algorithm(string pattern, string search) {
  int l = search.length();
  int s = pattern.length();

  string text = pattern + "$" + search;

  for(int i = s+1; i < s+1+l; i++) {
    int count = 0;
    for(int j = 0; j < s; j++) {
      if(text[j] == text[j+i]) count++;
      else break;
    }

    if(count == s) return true;
  }

  return false;
}

int main() {
  int N;

  cin >> N;

  string passwords[N];

  for(int i = 0; i < N; i++)
    cin >> passwords[i];

  long long int count = 0;

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(i != j)
        if(passwords[i].length() <= passwords[j].length())
          if(z_algorithm(passwords[i], passwords[j]))
            count++;

  cout << count << endl;

  return 0;
}