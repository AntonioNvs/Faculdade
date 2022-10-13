#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  if(N == 0) {
    cout << "*" << endl;
    cout << "*" << endl;
  } else if(N == 1) {
    cout << "I" << endl;
    cout << "*" << endl;
  } else if(N == 2) {
    cout << "II" << endl;
    cout << "*" << endl;
  } else if(N == 3) {
    cout << "III" << endl;
    cout << "*" << endl;
  } else if(N == 4) {
    cout << "IIII" << endl;
    cout << "*" << endl;
  } else if(N == 5) {
    cout << "IIIII" << endl;
    cout << "*" << endl;
  } else if(N == 6) {
    cout << "IIIII" << endl;
    cout << "I" << endl;
  } else if(N == 7) {
    cout << "IIIII" << endl;
    cout << "II" << endl;
  } else if(N == 8) {
    cout << "IIIII" << endl;
    cout << "III" << endl;
  } else if(N == 9) {
    cout << "IIIII" << endl;
    cout << "IIII" << endl;
  } else if(N == 10) {
    cout << "IIIII" << endl;
    cout << "IIIII" << endl;
  }
  
  return 0;
}