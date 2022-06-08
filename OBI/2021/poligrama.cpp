#include <cstring>
#include <iostream>

/*
  Para cada divisor do poligrama, teste se suas divisões possuem o mesmo
  número de letras cada uma. Por exemplo:

  bbaabb

  O divisor 2 resulta em ["bb", "aa", "bb"], no qual não da certo
  O divisor 3 resulta em ["bba", "abb"], o que é correto
*/

using namespace std;

bool verify(int interval, string poligrama) {
  int size = poligrama.length();
  int arr_size = (size / interval);
  
  int v[arr_size][26];

  memset(v, 0, sizeof(v));

  for(int i = 0; i < (size / interval); i++) {
    for(int j = i*interval; j < (i+1)*interval; j++) {
      int idx =  poligrama[j] - 'a';

      v[i][idx]++;
    }
  }

  for(int j = 0; j < 26; j++)
    for(int i = 1; i < arr_size; i++)
      if(v[i-1][j] != v[i][j]) 
        return false;

  return true;
}

int main() {
  int size;

  string poligrama;

  cin >> size >> poligrama;

  for(int i = size; i >= 2; i--) {
    if(size % i == 0) {
      if(verify(size/i, poligrama)) {
        for(int j = 0; j < size/i; j++)
          cout << poligrama[j];
        cout << endl;
        return 0;
      }
    }
  }

  cout << "*" << endl;
}