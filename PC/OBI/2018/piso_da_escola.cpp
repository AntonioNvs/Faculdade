#include <iostream>

using namespace std;

int main() {
  int L, C;

  cin >> L >> C;

  int f1 = L*C + (L-1)*(C-1);
  int f2 = 2*(C-1) + 2*(L-1);

  cout << f1 << endl << f2 << endl;

  return 0;
}