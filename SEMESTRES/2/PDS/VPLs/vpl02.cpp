#include <iostream>
#include <map>

using namespace std;

int main() {
  string word;
  
  map<char, int> hash;
  
  cin >> word;
  
  for(int i = 0; i < word.size(); i++)
    if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
        hash[word[i]]++;
        
  for(auto par : hash) {
      cout << par.first << ' ' << par.second << endl;
  }
  
  return 0;
}