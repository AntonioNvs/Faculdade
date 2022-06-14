#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;

  int res = (N-3) % 8;

  if(res == 3) cout << 1 << endl;
  else if(res == 4) cout << 2 << endl;
  else if(res == 5) cout << 3 << endl;

  return 0;
}