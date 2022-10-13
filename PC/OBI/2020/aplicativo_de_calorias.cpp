#include <bits/stdc++.h>

using namespace std;

int main() {
 int e1, e2, e3, x;
  cin >> e1 >> e2 >> e3 >> x;

  if(abs(e2 - e1) <= x)
    cout << e2 << endl;
  else
    cout << e3 << endl;
    
  return 0;
}