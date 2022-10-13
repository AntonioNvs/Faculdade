#include <iostream>

using namespace std;

int main() {
  int M, A, B;

  cin >> M >> A >> B;
  
  int third = M-A-B;
  
  cout << max(third, max(A, B));
  
  return 0;
}