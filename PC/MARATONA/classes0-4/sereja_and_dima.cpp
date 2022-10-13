#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;

  cin >> N;
  int cards[N];

  for(int i = 0; i < N; i++)
    cin >> cards[i];

  long long int s = 0, d = 0;

  int l = 0, r = N-1;
  int turn = 1;
  while(l <= r) {
    if(turn == 1) {
      if(cards[l] >= cards[r]) {
        s += cards[l];
        l++;
      } else {
        s += cards[r];
        r--;
      }
    } else {
      if(cards[l] >= cards[r]) {
        d += cards[l];
        l++;
      } else {
        d += cards[r];
        r--;
      }
    }

    turn *= -1;
  }

  cout << s << ' ' << d << endl;
  return 0;
}