#include <iostream>

using namespace std;

int main() {
  int N, s1, s2, size, sum1 = 0, sum2 = 0;

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> size;
    if(size == 1)
      sum1++;
    else
      sum2++;
  }

  cin >> s1 >> s2;

  if(s1 == sum1 && s2 == sum2)
    cout << "S" << endl;
  else
    cout << "N" << endl;

  return 0;
}