#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  string strA, strB, trash;
  unordered_map<char, int> mapA;
  unordered_map<char, int> mapB;

  getline(cin, trash, '\n');
  getline(cin, strA, '\n');
  getline(cin, strB, '\n');

  for(int i = 0; i < strA.size(); i++) {
    mapA[strA[i]]++;
    mapB[strB[i]]++;
  }

  for(auto tuple : mapA) {
    char c = tuple.first;
    int count = tuple.second;

    if(c == ' ' || c == '.' || c == ',')
      continue;

    if(mapB.find(c) != mapB.end()) {
      if(mapB[c] != count) {
        cout << "N" << endl;
        return 0;
      }

    } else {
      cout << "N" << endl;
      return 0;
    }
  }

  cout << "S" << endl;
  return 0;
}