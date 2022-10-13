#include <iostream>

using namespace std;

int main() {
  int T, count = 0;
  string state;
  float gas, alcool;

  cin >> T;

  while(T--) {
    cin >> state;
    cin >> gas >> alcool;

    if(gas*0.70 >= alcool) {
      cout << state << endl;
      count++;
    }
  }

  if(!count)
    cout << '*' << endl;

  return 0;
}