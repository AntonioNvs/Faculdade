#include <iostream>

using namespace std;

int sum_digit(int n) {
  int sum = 0;

  while(n != 0) {
    sum += n % 10;

    n = (int)(n/10);
  }

  return sum;
}

int main() {
  int A, B, S, mini = 99999999, maxi = -1;

  cin >> S >> A >> B;

  for(int i = A; i <= B; i++) {
    int result = sum_digit(i);

    if(result == S && i < mini)
      mini = i;
    if(result == S && i > maxi)
      maxi = i;
  }

  cout << mini << endl << maxi << endl;

  return 0;
}