#include <bits/stdc++.h>

using namespace std;

int main() {
  float l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  
  for(int c = x; c <= y; c++)
    if(k*c >= l && k*c <= r) {
      cout << "YES" << endl;
      return 0;
    }

  cout << "NO" << endl;

  return 0;
}