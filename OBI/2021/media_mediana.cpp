#include <iostream>

using namespace std;

int main() {
  int A, B;

  cin >> A >> B;

  cout << 2*min(A, B) - max(A, B) << endl;
  return 0;
}