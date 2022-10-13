#include <bits/stdc++.h>

using namespace std;

int main () {
  int T, A, B, C;
  cin >> T;

  while(T--) {
    cin >> A >> B >> C;
    int v1 = abs(A-1);
    int v2 = abs(B - C) + abs(C - 1);

    if(v1 < v2)
      cout << '1' << endl;
    else if(v1 > v2)
      cout << '2' << endl;
    else
      cout << '3' << endl;

  }
  return 0;
}