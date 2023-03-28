#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long int ll;

int main() { _
  int N; cin >> N;

  bool trips[100000];
  memset(trips, 0, sizeof(trips));
  /*
    5 -> 10
    10 -> 5
    6 -> 12
    12 -> 6
    7 -> 14
    14 -> 7

  */
  
  bool sit = false;
  int age = 4, k = 0;
  while(k < N) {
    if(sit) {
      trips[age] = true;
      age /= 2;
    } else {
      age++;
      if(trips[age]) {
        continue;
      }
      age *= 2;
      trips[age] = true;
    }
    k++;
    sit = !sit;
  }

  cout << age << endl;

  return 0;
}