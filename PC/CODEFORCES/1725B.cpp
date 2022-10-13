#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, D;

  cin >> N >> D;

  vector<int> powers;

  int tmp;
  for(int i = 0; i < N; i++) {
    cin >> tmp;
    powers.push_back(tmp);
  }

  sort(powers.begin(), powers.end());

  int l = 0, r = N-1;
  int ans = 0;

  while(l <= r) {
    if(l == r) {
      if(powers[l] > D) {
        ans++;
      }
      break;
    }
    if(powers[r] > D) {
      ans++;
      r--;
    } else {
      int t = powers[r];
      while(t <= D && l < r) {
        t += powers[r];
        l++;
      }

      if(t > D) {
        ans++;
        r--;
      }
    }
  }

  cout << ans << endl;

  return 0;
}