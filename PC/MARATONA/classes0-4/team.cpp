#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, v1, v2, v3;

  cin >> N;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    cin >> v1 >> v2 >> v3;
    if(v1 + v2 + v3 >= 2)
      ans++;
  }

  cout << ans << endl;
  return 0;
}